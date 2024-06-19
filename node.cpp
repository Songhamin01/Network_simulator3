#include "node.h"

int Node::nextId_ = 0;

bool Node::operator==(Node *a)
{
    if (a->id() == id_)
        return true;
    return false;
}

void Node::pushPacket(Packet* p)
{
    packets = p;
}
