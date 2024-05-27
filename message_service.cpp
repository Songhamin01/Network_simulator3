#include "message_service.h"

// 메시지를 전송한다
void MessageService::send(std::string message)
{
    Packet* p = new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(p);
}