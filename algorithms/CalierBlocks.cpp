#include "CalierBlocks.hpp"
#include <iostream>

int CalierBlocks::calculateA(std::vector<Task> const& tasks, unsigned int b, unsigned int cmax)
{
  for(auto i = 0u; i < b; i++)
  {
    int sum = 0;
    sum = std::accumulate(tasks.begin() + i, tasks.begin() + b + 1, 0, [](int sum, Task const& task)
                          {
                            return sum + task.p;
                          });

    if(cmax == (sum + tasks[i].insertTimeIntoMachine + tasks[b].q))
      return i;
  }
  return 0;
}

int CalierBlocks::calculateB(std::vector<Task> const& tasks, unsigned int cmax)
{
  int b = 0;
  for(auto i = 0u; i < tasks.size(); i++)
  {
    if(cmax == (tasks[i].insertTimeIntoMachine + tasks[i].q + tasks[i].p ))
      b = i;
  }
  return b;
}

int CalierBlocks::calculateC(std::vector<Task> const& tasks, unsigned int a, unsigned int b)
{
  int c = -1;
  for(auto i = a; i < b + 1; i++)
    if(tasks[i].q < tasks[b].q)
      c = i;
  return c;
}
