#pragma once

struct Task {
  unsigned int r, p, q, id = 0;
  unsigned int insertTimeIntoMachine = 0;
  bool operator==(Task const& comparedTask) const
  {
    return this->id == comparedTask.id;
  }
};
