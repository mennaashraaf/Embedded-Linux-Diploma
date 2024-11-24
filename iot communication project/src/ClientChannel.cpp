#include "ClientChannel.h"
#include <iostream>

ClientChannel::ClientChannel(Socket* socket) : Channel(socket) {}

void ClientChannel::start() {
    channelSocket->connect();  
    std::cout << "Client connected to server\n";
}

void ClientChannel::stop() {
    channelSocket->shutdown();
    std::cout << "Client disconnected\n";
}

void ClientChannel::send(const std::string& message) {
    channelSocket->send(message);
    std::cout << "Client: Sending message: " << message << "\n";
}

void ClientChannel::receive() {
    channelSocket->receive();
}
