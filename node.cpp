#include "node.h"

bool Node::operator==(Node *a)
{
    if (a->id_ == id_)
        return true;
    return false;
}