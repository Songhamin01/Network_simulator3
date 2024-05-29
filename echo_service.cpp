#include "echo_service.h"

void EchoService::result()
{
    std::cout << "EchoService: received \"" << host_->getPacket()->dataString() << "\" from " << ":" << host_->getPacket()->srcAddress().toString() << ":" << host_->getPacket()->srcPort() << ", send reply with same data" << std::endl;
}