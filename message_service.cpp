#include "message_service.h"

MessageService::~MessageService()
{
    delete p;
}

// 메시지를 전송한다
void MessageService::send(std::string message)
{
    p = new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(p);
}

void MessageService::result()
{
    std::cout << "MessageService: received \"" << host_->getPacket()->dataString() << "\" from " << host_->getPacket()->srcAddress().toString() << ":" << host_->getPacket()->srcPort() << std::endl;
}