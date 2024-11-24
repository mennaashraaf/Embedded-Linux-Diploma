#include <sys/types.h>
#include <stdio.h>
#include <unistd.h> //for close() to close sockfd
#include <signal.h>
#include <sys/socket.h> //for socket functions
#include <netinet/in.h> // for sockaddr_in
#include <arpa/inet.h> // for inet_addr func
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define PORT 7001
#define IP_ADDRESS "127.0.0.1"

//handle sigint
void sig_int_handler(int sig_nb){
    printf("Received SIGINT signal");
    exit(0);

}
void sig_child_handler(int sig_nb) {
    while (wait(NULL) > 0);
}
int main() {
    pid_t pid;
    char rcv_buffer[100];
    signal(SIGINT,sig_int_handler);
        signal(SIGCHLD, sig_child_handler);

    //creating socket file descriptor 
    int server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    int option_val=1;
    if (server_sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    //to configure various option for sockets
    int status = setsockopt(server_sockfd,SOL_SOCKET,SO_REUSEADDR,&option_val,sizeof(option_val));
    if (status < 0) {
        perror("setsockopt failed");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    //initializing struct elements to add port/ip info
    struct sockaddr_in server_addr ;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY; //Server must be able to receive packets from any interface

    //bind socket with address/port from struct sockaddr_in
    status=bind(server_sockfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));
    if (status < 0) {
        perror("bind failed");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    //listen on specified port for one connection only
    status=listen(server_sockfd,1);
    if (status < 0) {
        perror("listen failed");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    //initializing structure elements for client 
    struct sockaddr_in client_addr;
    socklen_t length_of_addr = sizeof(client_addr);
    int client_sockfd;

   //server always accept new connections from clients
    while(1) {
        client_sockfd=accept(server_sockfd,(struct sockaddr*)&client_addr,&length_of_addr);
        if(client_sockfd < 0) {
            perror("error in accepting connection");
            continue;
        }
        //creating child process to handle connection
        pid = fork();
        if(pid < 0) {
            perror("creation of child process has failed");
            close(client_sockfd);
            continue;
        }
        //child process
        if(pid == 0) {
            close(server_sockfd);
            //always receive commands until client sends “stop”
            while(1) {
                //initialize all elements of rcv_buffer to 0
                memset(rcv_buffer,0,sizeof(rcv_buffer));
                int bytes_read=read(client_sockfd,rcv_buffer,sizeof(rcv_buffer));
                //check if the received command is “stop”
                if(bytes_read <=0 || strncmp(rcv_buffer,"stop",4) == 0)
                    break;
            
            //execute commands from C code
            int cmd_status = system(rcv_buffer);

            //return the exit status of the command to the client
            send(client_sockfd,&cmd_status,sizeof(cmd_status),0);
            }
            close(client_sockfd);
            exit(EXIT_FAILURE);
        }
        //parent process
        else {
            close(client_sockfd);
            //handle zombie process
            //wait(NULL);
        }


    }
    return 0;

}
