#include "message_service.h"
#include "packet.h"
#include <iostream>

// 메시지를 전송한다
void MessageService::send(std::string message)
{
    p = new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(p);
}

void MessageService::result(Packet *p)
{
    std::string m = p->dataString();
    log(m);
    delete p;
}