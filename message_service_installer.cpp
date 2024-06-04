#include "message_service_installer.h"

// 호스트에 MessageService를 설치한다
MessageService *MessageServiceInstaller::install(Host *host)
{
    int thisPort = c_port;
    std::vector<Service *> ser = host->getSer();
    for (int i = 0; i < (int)ser.size(); ++i)
    {
        if (ser[i]->getPort() == thisPort)
        {
            thisPort++;
        }
    }
    m = new MessageService(host, thisPort, this->destAddress_, this->destPort_);
    this->ServiceInstaller::install(host, m);
    return m;
    
}