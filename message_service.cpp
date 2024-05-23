#include "message_service.h"

// 메시지를 전송한다
void MessageService::send(std::string message)
{
    Packet* p = new Packet(this->host_->address(), this->destAddress_, this->port_, this->destPort_, message);
    
}