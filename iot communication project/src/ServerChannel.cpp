#include "ServerChannel.h"
#include <iostream>

ServerChannel::ServerChannel(Socket* socket) : Channel(socket) {}

void ServerChannel::start() {
    channelSocket->connect();  
    std::cout << "Server started\n";
}

void ServerChannel::stop() {
    channelSocket->shutdown();
    std::cout << "Server stopped\n";
}

void ServerChannel::send(const std::string& message) {
    channelSocket->send(message);
    std::cout << "Server: Sending message: " << message << "\n";
}

void ServerChannel::receive() {
    channelSocket->receive();
}
