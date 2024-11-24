#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "Socket.h"
#include <netinet/in.h>

class UDPSocket : public Socket {
private:
    int sock_fd;
    struct sockaddr_in multicast_addr;

public:
    UDPSocket(const std::string& multicast_ip, int port); //for server
    UDPSocket(int port);                        //for client          
    ~UDPSocket() override;

    void bind(); 
    void join_multicast_group(const std::string& multicast_ip);
    void connect() override {}
    void send(const std::string& message) override;
    void receive() override;
    void shutdown() override;
};

#endif 
