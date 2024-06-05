#include "node.h"

int Node::nextId_ = 0;

Node::~Node()
{
    // for (int i = 0; i < (int)links_.size(); ++i)
    // {
    //     delete links_[i];
    // }
}

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
