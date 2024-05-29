#include "host.h"
#include <cstdlib>
#include <iostream>

// 호스트와 설치된 서비스를 전부 초기화한다.
void Host::initialize()
{
    services_.clear();  
}

// 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
void Host::send(Packet *packet)
{
    int num = rand() % links_.size();
    links_.at(num)->nextLink(this, packet);
    std::cout << "Host #" << id() << ": sending packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataString().length() << " bytes)" << std::endl;
}

void Host::receive()
{
    bool isTrue = false;
    for(int i = 0; i < services_.size(); ++i)
    {
        if(services_[i]->getPort() == packets->destPort())
        {
            isTrue = true;
            break;
        }
    }
    if (!isTrue)
    {
        std::cout << "Host #" << id() << ": no service for packet (from: " << packets->srcAddress().toString() << ", to: " << packets->destAddress().toString() << ", " << packets->dataString().length() << " bytes" << std::endl;
    }
}