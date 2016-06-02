#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Task
{
  std::vector<int> timesOnMaschines;
};

int neh(std::vector<Task> const& tasks)
{
  auto numberOfMaschines = tasks[0].timesOnMaschines.size();
  std::vector<int> maschine (numberOfMaschines);

  for(std::size_t j = 0; j < tasks.size(); j++)
  {
    maschine[0] = maschine[0] + tasks[j].timesOnMaschines[0];
    for(std::size_t i = 1; i < tasks[j].timesOnMaschines.size(); i++)
    {
      maschine[i] = std::max(maschine[i] ,maschine[i-1]) + tasks[j].timesOnMaschines[i];
    }
  }
  return maschine.back();
}

std::vector<Task> insertInOptimalPosition(std::vector<Task> const& tasks, Task const& taskToInsert)
{
  auto minimum = std::numeric_limits<int>::max();
  auto bestInsertPosition = 0;

  for(std::size_t i = 0; i < tasks.size() + 1; i++)
  {
    auto tasksCopy = tasks;
    tasksCopy.insert(tasksCopy.begin() + i, taskToInsert);
    auto cmax = neh(tasksCopy);
    if(cmax < minimum)
    {
      bestInsertPosition = i;
      minimum = cmax;
    }
  }
  auto outputTasks = tasks;
  outputTasks.insert(outputTasks.begin() + bestInsertPosition, taskToInsert);
  return outputTasks;
}

int main()
{
  int numberOfTasks, numberOfMaschines = 0;
  std::vector<Task> loadedTasks;

  std::cin >> numberOfTasks >> numberOfMaschines;

  for(int i = 0; i < numberOfTasks; i++)
  {
    Task task;
    for(int j = 0; j < numberOfMaschines; j++)
    {
      int time = 0;
      std::cin >> time;
      task.timesOnMaschines.push_back(time);
    }
    loadedTasks.push_back(task);
  }

  std::sort(loadedTasks.begin(), loadedTasks.end(), [](Task const& left, Task const& right)
            {
              auto leftTimesSum = std::accumulate(left.timesOnMaschines.begin(),
                                                  left.timesOnMaschines.end(),
                                                  0);
              auto rightTimesSum = std::accumulate(right.timesOnMaschines.begin(),
                                                   right.timesOnMaschines.end(),
                                                   0);
              return leftTimesSum > rightTimesSum;
            });

  auto optimalOrder = std::vector<Task> {};

  for(auto const& task : loadedTasks)
    optimalOrder = insertInOptimalPosition(optimalOrder, task);

  std::cout << neh(optimalOrder) << std::endl;
}
