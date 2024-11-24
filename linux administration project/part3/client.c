#include <sys/types.h>
#include <stdio.h>
#include <unistd.h> //for close() to close sockfd
#include <signal.h>
#include <sys/socket.h> //for socket functions
#include <netinet/in.h> // for sockaddr_in
#include <arpa/inet.h> // for inet_addr func
#include <stdlib.h>
#include <string.h>
int main(int argc , char *argv[]){
    int status,cmd_status;
    char rcv_buffer[100];
    //handling arguments
    //Client must take remote IP/Port (that it should connect to) as command line arguments
    if(argc !=3) {
        printf("enter 1)ip address and 2)port number");
        exit(EXIT_FAILURE);
    }
    //creating socket file descriptor 
    int client_sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (client_sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    //initializing struct elements for address
    struct sockaddr_in server_addr ;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr=inet_addr(argv[1]);

    //connect to the server
    status=connect(client_sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    if (status < 0) {
        perror("connection failed");
        close(client_sockfd);
        exit(EXIT_FAILURE);
    }

    //Client must ask the user to input a command to be executed on the server (this command can include arguments or flags)
    while(1) {
        printf("enter command: ");
        fflush(stdout);
        //read a line of input from the standard input (stdin) into a buffer
        fgets(rcv_buffer, sizeof(rcv_buffer), stdin);
        rcv_buffer[strcspn(rcv_buffer, "\n")] = 0; // remove newline 
        if(strncmp(rcv_buffer,"stop",4) == 0){
            send(client_sockfd,rcv_buffer,strlen(rcv_buffer),0);
            break;
        }
        //send command to server
        send(client_sockfd, rcv_buffer, strlen(rcv_buffer), 0);

        //receive exit status of command from server
        read(client_sockfd,&cmd_status,sizeof(cmd_status));
         printf("command exit status: %d\n", cmd_status);
    }

 close(client_sockfd);
    return 0;
}

