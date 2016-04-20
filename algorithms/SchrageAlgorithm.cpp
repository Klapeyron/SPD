#include "SchrageAlgorithm.hpp"

int schrage(std::vector<Task> const& tasks)
{
  auto loadedTasksLambda = [](Task const& left, Task const& right) { return left.r > right.r; };
  auto readyTasksLambda = [](Task const& left, Task const& right) { return left.q < right.q; };

  std::priority_queue<Task, std::vector<Task>, decltype(loadedTasksLambda)> loadedTasks{loadedTasksLambda};
  std::priority_queue<Task, std::vector<Task>, decltype(readyTasksLambda)> readyTasks{readyTasksLambda};

  unsigned int time = 0, cmax = 0;

  for(auto const& task : tasks)
    loadedTasks.push(task);

  while( not (loadedTasks.empty() and readyTasks.empty()) )
  {
    while( loadedTasks.top().r <= time and not loadedTasks.empty() )
    {
      readyTasks.push( loadedTasks.top() );
      loadedTasks.pop();
    }
    if(readyTasks.empty())
      time = loadedTasks.top().r;
    else
    {
      time += readyTasks.top().p;
      cmax = std::max(cmax, readyTasks.top().q + time);
      readyTasks.pop();
    }
  }
  return cmax;
}
