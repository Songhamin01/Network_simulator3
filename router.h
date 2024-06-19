#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"

class Link;

struct RoutingEntry {
public:
  RoutingEntry() : destination(0){}
  Address destination;
  Link *nextLink;
};

class Router : public Node {
private:
  virtual std::string name(){ return "Router"; }
  
protected:
  std::vector<RoutingEntry> routingTable_;

public:
  ~Router();
  void receiving();
};

#endif