#include "ClientChannel.h"
#include "UDPSocket.h"
#include <iostream>

int main() {
    UDPSocket* clientSocket = new UDPSocket(8080);
    clientSocket->bind();
    clientSocket->join_multicast_group("239.0.0.1");

    ClientChannel client(clientSocket);

    while (true) {
        client.receive();  
    }

    client.stop();
    delete clientSocket;
    return 0;
}
