#ifndef BULK_SEND_SERVICE_H
#define BULK_SEND_SERVICE_H

#include "host.h"
#include "service.h"
#include "simulator.h"

#define c_port 1000
#define PACKET_SIZE 512

class BulkSendService : Service {
  friend class BulkSendServiceInstaller;

private:
  Packet *p;
  Address destAddr;
  short destP;
  double delay_;
  double startT;
  double stopT;
  std::vector<Packet *> vec_packet;
  std::string d;
  virtual std::string name() { return "BulkSendService";}
  BulkSendService(Host *host, Address destAddress, short destPort,
                  double delay = 1, double startTime = 0,
                  double stopTime = 10.0)
  : Service(host, c_port), destAddr(destAddress), destP(destPort), delay_(delay), startT(startTime), stopT(stopTime){}

public:
  void send()
  {

  }
};

#endif