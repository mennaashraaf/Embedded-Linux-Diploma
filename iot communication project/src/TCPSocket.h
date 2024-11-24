#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "Socket.h"
#include <string>
#include <netinet/in.h>

class TCPSocket : public Socket {
private:
    int sock_fd;
    struct sockaddr_in address;

public:
    TCPSocket(int port);                    
    TCPSocket(const std::string& ip, int port); 
    ~TCPSocket() override;

    void connect() override;
    void listen();
    void accept();
    void send(const std::string& message) override;
    void receive() override;
    void shutdown() override;
};

#endif 
