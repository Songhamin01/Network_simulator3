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

void EchoService::result(Packet *p)
{
    std::string m = "received \"" + packets->dataString() + "\" from " + packets->srcAddress().toString() + ":" + std::to_string(packets->srcPort()) + " send reply with same data";
    log(m);
    send(p);
    delete p;
}

void EchoService::send(Packet *p)
{
    packets = new Packet(host_->address(), p->srcAddress(), port_, p->srcPort(), p->data());
    host_->send(packets);
    // pac.push_back(packets);
}