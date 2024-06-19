#ifndef PACKET_SINK_SERVICE_H
#define PACKET_SINK_SERVICE_H

#include "service.h"
#include <string>

class PacketSinkService : public Service {
  friend class PacketSinkServiceInstaller;
private:
  int byte;
  PacketSinkService(Host *host, short port) : Service(host, port){};
  virtual std::string name(){ return "PacketSinkService"; }

public:
  void result(Packet *p)
  {
    byte += (int)p->data().size();
    std::string m = "received total " + std::to_string(byte) + " bytes";
    log(m);
    delete p;
  }
};

#endif