#include "SchrageWithDivisionAlgorithm.hpp"

int schrageWithDivision(std::vector<Task> & tasks)
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
    Task taskOnMachine;
    while( loadedTasks.top().r <= time and not loadedTasks.empty() )
    {
      auto loadedTask = loadedTasks.top();
      loadedTasks.pop();
      readyTasks.push(loadedTask);

      if(loadedTask.q > taskOnMachine.q)
      {
        taskOnMachine.p = time - loadedTask.r;
        time = loadedTask.r;
        if(taskOnMachine.p not_eq 0)
          readyTasks.push(taskOnMachine);
      }
    }
    if(readyTasks.empty())
      time = loadedTasks.top().r;
    else
    {
      time += readyTasks.top().p;
      cmax = std::max(cmax, readyTasks.top().q + time);
      taskOnMachine = readyTasks.top();
      tasksOnMaschineInOrder.push_back(taskOnMachine);
      readyTasks.pop();
    }
  }
  tasks = tasksOnMaschineInOrder;
  return cmax;
}
