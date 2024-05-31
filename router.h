#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include <iostream>

struct RoutingEntry {
public:
  Address destination;
  Link *nextLink;
  RoutingEntry() : destination(0){}
};

class Router : public Node {
protected:
  std::vector<RoutingEntry> routingTable_;

public:
  ~Router();
  void receiving();
};

#endif