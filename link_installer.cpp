#include "link_installer.h"
#include <iostream>

// 노드 a, b 사이에 링크를 설치하고 반환한다.
Link *LinkInstaller::install(Node *a, Node *b)
{
    Link *newLink = new Link(a, b);
    a->links_.push_back(newLink);
    b->links_.push_back(newLink);
    return newLink;
}