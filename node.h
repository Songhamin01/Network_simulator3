#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "object.h"
#include "packet.h"
#include <vector>

class Node : public Object {
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;
  virtual std::string name(){ return "Node"; }

protected:
  Packet *packets;
  std::vector<Link *> links_;

public:
  Node() : id_(nextId_++) {}
  virtual ~Node(){};
  int id() const { return id_; }
  Packet *getPacket() {return packets;}
  bool operator==(Node *a);
  void pushPacket(Packet *p);
  virtual void receiving(Packet *p) = 0;
};

#endif