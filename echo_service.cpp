#include "echo_service.h"
#include "packet.h"
#include <iostream>
#include <vector>

EchoService::~EchoService()
{
    // for(Packet *p : pac)
    // {
    //     delete p;
    // }
}

void EchoService::result()
{
    std::cout << "EchoService: received \"" << host_->getPacket()->dataString() << "\" from " << ":" << host_->getPacket()->srcAddress().toString() << ":" << host_->getPacket()->srcPort() << ", send reply with same data" << std::endl;
    send();
    delete host_->getPacket();
}

void EchoService::send()
{
    packets = new Packet(host_->address(), host_->getPacket()->srcAddress(), port_, host_->getPacket()->srcPort(), host_->getPacket()->data());
    host_->send(packets);
    // pac.push_back(packets);
}