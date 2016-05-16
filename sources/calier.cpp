#include "CalierAlgorithm.hpp"
#include <fstream>

int main()
{
  std::vector<Task> loadedTasks;
  std::ifstream plik ("dane.dat");
  plik.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  int i = 0;
  for(Task task; plik >> task.r >> task.p >> task.q;)
  {
    task.id = i;
    loadedTasks.push_back(task);
    i++;
  }
  std::cout << calier(loadedTasks) << std::endl;
}
