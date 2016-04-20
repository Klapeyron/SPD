#include "SchrageWithDivisionAlgorithm.hpp"

int main()
{
  std::vector<Task> loadedTasks;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  for(Task task; std::cin >> task.r >> task.p >> task.q;)
    loadedTasks.push_back(task);

  std::cout << schrageWithDivision(loadedTasks) << std::endl;
}
