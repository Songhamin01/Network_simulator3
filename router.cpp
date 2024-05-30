#include "router.h"

Router::~Router()
{
    routingTable_.clear();
}

void Router::receiving()
{
    bool isTrue = false;
    for(int i = 0; i < routingTable_.size(); ++i)
    {
        if(routingTable_[i].destination == packets->destAddress())
        {
            isTrue = true;
            std::cout << "Router #" << id() << ": forwarding packet (from: " << packets->srcAddress().toString() << ", to: " << packets->destAddress().toString() << ", " << packets->dataString().length() << "bytes)" << std::endl;
            routingTable_[i].nextLink->whatLink(this, packets);
            break;
        }
    }

    if (!isTrue)
    {
        std::cout << "Router #" << id() << ": no router for packet (from: " << packets->srcAddress().toString() << ", to: " << packets->destAddress().toString() << ", " << packets->dataString().length() << " bytes)" << std::endl;
    }
}