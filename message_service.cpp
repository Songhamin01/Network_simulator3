#include "message_service.h"
#include "packet.h"
#include <iostream>

MessageService::~MessageService()
{
    // for(Packet *p : pac)
    // {
    //     delete p;
    // }
}

// 메시지를 전송한다
void MessageService::send(std::string message)
{
    p = new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(p);
    // pac.push_back(p);
}

void MessageService::result()
{
    std::cout << "MessageService: received \"" << host_->getPacket()->dataString() << "\" from " << host_->getPacket()->srcAddress().toString() << ":" << host_->getPacket()->srcPort() << std::endl;
}