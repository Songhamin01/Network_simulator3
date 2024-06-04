#include "link.h"
#include "node.h"
#include "router.h"
#include <iostream>

void Link::whatLink(Node *n, Packet *p)
{
    Node *nextNode = other(n);
    nextNode->pushPacket(p);
    std::cout << "Link: forwarding packet from node #" << n->id() << ", to node #" << other(n)->id() << std::endl;
    nextNode->receiving();
}