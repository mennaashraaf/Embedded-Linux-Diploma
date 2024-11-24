#include "TCPSocket.h"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>      
#include <netinet/in.h>     
#include <sys/socket.h>     

TCPSocket::TCPSocket(int port) { 
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        std::cerr << "Failed to create socket\n";
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(sock_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Binding failed\n";
        exit(1);
    }
}

TCPSocket::TCPSocket(const std::string& ip, int port) { 
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        std::cerr << "Failed to create socket\n";
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &address.sin_addr);
}

TCPSocket::~TCPSocket() {
    close(sock_fd);
}

void TCPSocket::connect() {
    if (::connect(sock_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Connection failed\n";
        exit(1);
    }
    std::cout << "Connected to server\n";
}

void TCPSocket::listen() { 
    ::listen(sock_fd, 5);
    std::cout << "Listening on port " << ntohs(address.sin_port) << "\n";
}

void TCPSocket::accept() { 
    int client_sock = ::accept(sock_fd, nullptr, nullptr);
    if (client_sock < 0) {
        std::cerr << "Failed to accept client\n";
        exit(1);
    }
    close(sock_fd);
    sock_fd = client_sock; 
    std::cout << "Client connected\n";
}

void TCPSocket::send(const std::string& message) {
    ::send(sock_fd, message.c_str(), message.size(), 0);
}

void TCPSocket::receive() {
    char buffer[1024] = {0};
    int bytes = read(sock_fd, buffer, sizeof(buffer));
    if (bytes > 0) {
        std::cout << "Received: " << buffer << "\n";
    } else {
        std::cerr << "No message received\n";
    }
}

void TCPSocket::shutdown() {
    close(sock_fd);
    std::cout << "Connection closed\n";
}
