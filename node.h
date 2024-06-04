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
  std::vector<Link *> links_;

public:
  Node() : id_(nextId_++) {}
  virtual ~Node();
  int id() const { return id_; }
  Packet *getPacket() {return packets;}
  bool operator==(Node *a);
  void pushPacket(Packet *p);
  virtual void receiving() = 0;
};

#endif