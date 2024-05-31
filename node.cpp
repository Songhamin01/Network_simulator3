#include "node.h"

Node::~Node()
{
    delete packets;
}

bool Node::operator==(Node *a)
{
    if (a->id_ == id_)
        return true;
    return false;
}

void Node::pushPacket(Packet* p)
{
    packets = p;
}
