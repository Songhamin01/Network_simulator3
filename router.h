#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include <iostream>

class Link;

struct RoutingEntry {
public:
  RoutingEntry() : destination(0){}
  Address destination;
  Link *nextLink;
};

class Router : public Node {
protected:
  std::vector<RoutingEntry> routingTable_;

public:
  ~Router();
  void receiving();
};

#endif