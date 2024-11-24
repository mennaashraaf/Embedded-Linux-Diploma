#include "UDPSocket.h"
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

UDPSocket::UDPSocket(const std::string& multicast_ip, int port) { 
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        std::cerr << "Failed to create socket\n";
        exit(1);
    }

    multicast_addr.sin_family = AF_INET;
    multicast_addr.sin_addr.s_addr = inet_addr(multicast_ip.c_str());
    multicast_addr.sin_port = htons(port);
}

UDPSocket::UDPSocket(int port) { 
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        std::cerr << "Failed to create socket\n";
        exit(1);
    }

    multicast_addr.sin_family = AF_INET;
    multicast_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    multicast_addr.sin_port = htons(port);
}

UDPSocket::~UDPSocket() {
    close(sock_fd);
}

void UDPSocket::bind() {
    if (::bind(sock_fd, (struct sockaddr*)&multicast_addr, sizeof(multicast_addr)) < 0) {
        std::cerr << "Binding failed\n";
        exit(1);
    }
}

void UDPSocket::join_multicast_group(const std::string& multicast_ip) {
    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr = inet_addr(multicast_ip.c_str());
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(sock_fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
        std::cerr << "Failed to join multicast group\n";
        exit(1);
    }
}

void UDPSocket::send(const std::string& message) {
    sendto(sock_fd, message.c_str(), message.size(), 0, (struct sockaddr*)&multicast_addr, sizeof(multicast_addr));
}

void UDPSocket::receive() {
    char buffer[1024] = {0};
    socklen_t addr_len = sizeof(multicast_addr);
    int bytes = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&multicast_addr, &addr_len);
    if (bytes > 0) {
        std::cout << "Received multicast message: " << buffer << "\n";
    }
}

void UDPSocket::shutdown() {
    close(sock_fd);
    std::cout << "Socket closed\n";
}
