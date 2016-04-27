#include "CalierAlgorithm.hpp"
#include <fstream>

int main()
{
  std::vector<Task> loadedTasks;
  std::ifstream plik ("dane.dat");
  plik.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  for(Task task; plik >> task.r >> task.p >> task.q;)
    loadedTasks.push_back(task);

  std::cout << calier(loadedTasks) << std::endl;
}
