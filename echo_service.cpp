#include "echo_service.h"

EchoService::~EchoService()
{
    delete packets;
}

void EchoService::result()
{
    std::cout << "EchoService: received \"" << host_->getPacket()->dataString() << "\" from " << ":" << host_->getPacket()->srcAddress().toString() << ":" << host_->getPacket()->srcPort() << ", send reply with same data" << std::endl;
}

void EchoService::send()
{
    packets = new Packet(host_->address(), host_->getPacket()->srcAddress(), port_, host_->getPacket()->srcPort(), host_->getPacket()->data());
    host_->send(packets);
}