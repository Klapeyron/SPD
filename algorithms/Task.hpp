#pragma once

struct Task {
  unsigned int r,p,q;
  unsigned int insertTimeIntoMachine = 0;
  bool operator==(Task const& comparedTask) const { return this->r == comparedTask.r and this->p == comparedTask.p and this->q == comparedTask.q; }
};
