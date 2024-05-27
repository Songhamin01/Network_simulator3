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
    // int num = rand % 
    std::cout << "Host #" << id() << ": sending packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataString().length() << " bytes)" << std::endl;
}