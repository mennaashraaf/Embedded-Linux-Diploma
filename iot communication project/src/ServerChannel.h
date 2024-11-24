#ifndef SERVERCHANNEL_H
#define SERVERCHANNEL_H

#include "Channel.h"

class ServerChannel : public Channel {
public:
    explicit ServerChannel(Socket* socket);
    ~ServerChannel() override = default;
    void start() override;
    void stop() override;
    void send(const std::string& message) override;
    void receive() override;
};

#endif 
