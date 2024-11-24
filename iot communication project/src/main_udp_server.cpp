#include "ServerChannel.h"
#include "UDPSocket.h"
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    UDPSocket* serverSocket = new UDPSocket("239.0.0.1", 8080);
    ServerChannel server(serverSocket);

    while (true) {
        server.send("System update at 10:00 AM");
        std::this_thread::sleep_for(std::chrono::seconds(5));  
    }

    server.stop();
    delete serverSocket;
    return 0;
}
