#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Task
{
  int czasWykonania, kara, termin = 0;
};

std::vector<Task> tasks;

bool bit(int a, int i)
{
  if(a & (1 << i))
    return true;
  return false;
}

int clear(int a, int i)
{
  return a &= ~(1 << i);
}

int kara(int c, int i)
{
  return std::max(0, (c - tasks[i].termin) * tasks[i].kara);
}

int end(int a)
{
  int koniec(0);
  for(auto i = 0u; i < tasks.size(); i++)
    if(bit(a, i))
      koniec += tasks[i].czasWykonania;
  return koniec;
}
  
int main()
{
  for(Task t; std::cin >> t.czasWykonania >> t.kara >> t.termin;)
    tasks.push_back(t);

  std::vector<int> OPT(pow(2, tasks.size()-1), std::numeric_limits<int>::max());
  OPT[0] = 0;

  int s,c = 0;
  
  for(auto a = 1u; a < pow(2, tasks.size()); a++)
  {
    c = end(a);
    for(auto i = 0u; i < tasks.size(); i++)
    {
      if(bit(a, i))
      {
        s = kara(c, i);
        auto address = clear(a, i);
        s += OPT[address];
        if(s < OPT[a])
          OPT[a] = s;
      }
    }
  }
  std::cout << OPT.back() << std::endl;
}
