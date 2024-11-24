#ifndef CLIENTCHANNEL_H
#define CLIENTCHANNEL_H

#include "Channel.h"

class ClientChannel : public Channel {
public:
    explicit ClientChannel(Socket* socket);
    ~ClientChannel() override = default;
    void start() override;
    void stop() override;
    void send(const std::string& message) override;
    void receive() override;
};

#endif // CLIENTCHANNEL_H
