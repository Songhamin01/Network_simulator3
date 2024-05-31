#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include <vector>

class Node {
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;

protected:
  Packet *packets;


public:
  Node() : id_(nextId_++) {}
  ~Node();
  int id() const { return id_; }
  Packet *getPacket() {return packets;}
  std::vector<Link *> links_;
  bool operator==(Node *a);
  void pushPacket(Packet *p);
  virtual void receiving() = 0;
};

#endif