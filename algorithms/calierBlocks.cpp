#include "calierBlocks.hpp"

int CalierBlocks::calculateA(std::vector<Task> const& tasks, unsigned int b)
{
  unsigned int cmax = schrage(tasks);
  auto iter = std::min_element(tasks.begin(), tasks.end(), [&tasks,cmax,b](Task const& left, Task const&)
                               {
                                 auto taskPosition = std::find(tasks.begin(), tasks.end(), left);
                                 auto sum = std::accumulate(taskPosition, tasks.begin()+b, 0,
                                                            [](int sum, Task const& task)
  {
    return sum + task.p;
  });
                                 return cmax == left.r + sum + tasks[b].q;
                               });
  return std::distance(tasks.begin(), iter);
}

int CalierBlocks::calculateB(std::vector<Task> const& tasks)
{
  unsigned int cmax = schrage(tasks);
  auto iter = std::max_element(tasks.begin(), tasks.end(), [cmax](Task const& task, Task const&)
                               {
                                 return cmax == task.insertTimeIntoMachine + task.q;
                               });
  return std::distance(tasks.begin(), iter);
}

int CalierBlocks::calculateC(std::vector<Task> const& tasks, unsigned int a, unsigned int b)
{  
  auto iter = std::max_element(tasks.begin()+a, tasks.begin()+b, [&tasks,b](Task const& task, Task const&)
                               {
                                 return task.q < tasks[b].q;
                               });
  return std::distance(tasks.begin(), iter);
}

