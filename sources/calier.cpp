#include "CalierAlgorithm.hpp"
#include <iostream>

int main()
{
  std::vector<Task> loadedTasks;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  int i = 0;
  for(Task task; std::cin >> task.r >> task.p >> task.q;)
  {
    task.id = i;
    loadedTasks.push_back(task);
    i++;
  }
  std::cout << calier(loadedTasks) << std::endl;
}
