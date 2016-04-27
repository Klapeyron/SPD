#include "SchrageAlgorithm.hpp"

int schrage(std::vector<Task> & tasks)
{
  auto loadedTasksLambda = [](Task const& left, Task const& right) { return left.r > right.r; };
  auto readyTasksLambda = [](Task const& left, Task const& right) { return left.q < right.q; };

  std::priority_queue<Task, std::vector<Task>, decltype(loadedTasksLambda)> loadedTasks{loadedTasksLambda};
  std::priority_queue<Task, std::vector<Task>, decltype(readyTasksLambda)> readyTasks{readyTasksLambda};

  std::vector<Task> tasksOnMaschineInOrder;
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
      auto taskReadyToInsert = readyTasks.top();
      taskReadyToInsert.insertTimeIntoMachine = time;
      tasksOnMaschineInOrder.push_back(taskReadyToInsert);
      time += readyTasks.top().p;
      cmax = std::max(cmax, readyTasks.top().q + time);
      readyTasks.pop();
    }
  }
  tasks = tasksOnMaschineInOrder;
  return cmax;
}
