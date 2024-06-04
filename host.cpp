#include "host.h"
#include <cstdlib>
#include <iostream>

Host::~Host()
{
    for (int i = 0; i < services_.size(); ++i)
    {
        delete services_[i];
    }
}

// 호스트와 설치된 서비스를 전부 초기화한다.
void Host::initialize()
{
    for(int i = 0; i < services_.size(); ++i)
    {
        services_[i] = nullptr;
    }
}

// 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
void Host::send(Packet *packet)
{
    int num = rand() % links_.size();
    std::cout << "Host #" << id() << ": sending packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataString().length() << " bytes)" << std::endl;
    links_.at(num)->whatLink(this, packet);
}

void Host::receiving()
{
    bool isTrue = false;
    std::cout << "Host #" << id() << ": received packet, destination port: " << packets->destPort() << std::endl;
    for(int i = 0; i < (int)services_.size(); ++i)
    {
        if(services_[i]->getPort() == packets->destPort())
        {
            services_[i]->result();
            isTrue = true;
            break;
        }
    }
    if (!isTrue)
    {
        std::cout << "Host #" << id() << ": no service for packet (from: " << packets->srcAddress().toString() << ", to: " << packets->destAddress().toString() << ", " << packets->dataString().length() << " bytes" << std::endl;
    }
}