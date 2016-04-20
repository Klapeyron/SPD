#include "CalierBlocks.hpp"

int CalierBlocks::calculateA(std::vector<Task> & tasks, unsigned int b)
{
  unsigned int cmax = schrage(tasks);
  auto iter = std::min_element(tasks.begin(), tasks.end(), [&tasks,cmax,b](Task const& left, Task const& right)
                               {
                                 auto leftTaskPosition = std::find(tasks.begin(), tasks.end(), left);
                                 auto rightTaskPosition = std::find(tasks.begin(), tasks.end(), right);
                                 auto leftTaskDistance = std::distance(tasks.begin(), leftTaskPosition);
                                 auto rightTaskDistance = std::distance(tasks.begin(), rightTaskPosition);

                                 auto sum = std::accumulate(leftTaskPosition, tasks.begin() + b, 0,
                                                            [](int sum, Task const& task)  {
                                                              return sum + task.p;
                                                            });

                                 return cmax == left.r + sum + tasks[b].q and leftTaskDistance < rightTaskDistance;
                               });
  return std::distance(tasks.begin(), iter);
}

int CalierBlocks::calculateB(std::vector<Task> & tasks)
{
  unsigned int cmax = schrage(tasks);
  auto iter = std::max_element(tasks.begin(), tasks.end(), [&tasks,cmax](Task const& left, Task const& right)
                               {
                                 auto leftTaskDistance = std::distance(tasks.begin(), std::find(tasks.begin(),tasks.end(), left));
                                 auto rightTaskDistance = std::distance(tasks.begin(), std::find(tasks.begin(),tasks.end(), right));

                                 return cmax == left.insertTimeIntoMachine + left.q and leftTaskDistance < rightTaskDistance;
                               });
  return std::distance(tasks.begin(), iter);
}

int CalierBlocks::calculateC(std::vector<Task> & tasks, unsigned int a, unsigned int b)
{
  auto iter = std::max_element(tasks.begin() + a, tasks.begin() + b, [&tasks,a,b](Task const& left, Task const& right)
                               {
                                 auto leftTaskDistance = std::distance(tasks.begin() + a, std::find(tasks.begin() + a,tasks.begin() + b, left));
                                 auto rightTaskDistance = std::distance(tasks.begin() + a, std::find(tasks.begin() + a,tasks.begin() + b, right));

                                 return left.q < tasks[b].q and leftTaskDistance < rightTaskDistance;
                               });
  return std::distance(tasks.begin(), iter);
}
