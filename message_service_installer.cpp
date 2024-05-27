#include "message_service_installer.h"

// 호스트에 MessageService를 설치한다
MessageService *MessageServiceInstaller::install(Host *host)
{
    m = new MessageService(host, host->address().toShort(), this->destAddress_, this->destPort_);
    ServiceInstaller::install(host, m);
    return m;
}