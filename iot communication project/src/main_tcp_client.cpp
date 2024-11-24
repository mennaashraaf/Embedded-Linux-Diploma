#include "ClientChannel.h"
#include "TCPSocket.h"
#include <iostream>

int main() {
    TCPSocket* clientSocket = new TCPSocket("127.0.0.1", 8080);
    ClientChannel client(clientSocket);

    client.start();
    client.send("Hello, Server!");
    client.receive();  

    client.stop();
    
    return 0;
}
