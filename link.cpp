#include "link.h"
#include "node.h"
#include "router.h"
#include "simulator.h"
#include <iostream>
#include <functional>

void Link::whatLink(Node *n, Packet *p)
{
    std::string m = "packet in: ";
    m += p->toString() + " from " + n->toString();
    log(m);

    std::function<void()> f = [n, p]()->void
    {
        std::string m = "packet out: ";
        m += p->toString() + " to " + other(n).
    }
    // Node *nextNode = other(n);
    // nextNode->pushPacket(p);
    // std::cout << "Link: forwarding packet from node #" << n->id() << ", to node #" << other(n)->id() << std::endl;
    // nextNode->receiving();
}