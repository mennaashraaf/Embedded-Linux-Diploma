#ifndef CHANNEL_H
#define CHANNEL_H

#include "Socket.h"
#include <string>

class Channel {
protected:
    Socket* channelSocket; 

public:
    explicit Channel(Socket* socket) : channelSocket(socket) {}
    virtual ~Channel(){
        if (channelSocket) {
            delete channelSocket; 
            channelSocket = nullptr;
        }
    }
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void send(const std::string& message) = 0;
    virtual void receive() = 0;
};

#endif 
