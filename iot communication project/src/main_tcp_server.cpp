#include "ServerChannel.h"
#include "TCPSocket.h"
#include <iostream>

int main() {
    TCPSocket* serverSocket = new TCPSocket(8080);
    ServerChannel server(serverSocket);

    serverSocket->listen();
    serverSocket->accept();

    server.receive(); 
    server.send("Acknowledgment. Current Temperature is 39°C "); 
    server.send("hello from server(menna's laptop)");
    server.stop();
    
    return 0;
}
