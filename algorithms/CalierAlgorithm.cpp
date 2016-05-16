#include "CalierAlgorithm.hpp"

int UB = std::numeric_limits<int>::max();

int calier(std::vector<Task> tasks)
{
  std::cout << "CARLIER" << std::endl;
  int U = schrage(tasks);
  std::cout << "U i UB :" << U << " " << UB << std::endl;
  if(U < UB)
    UB = U;

  int b = CalierBlocks::calculateB(tasks, UB);
  int a = CalierBlocks::calculateA(tasks, b, UB);
  int c = CalierBlocks::calculateC(tasks, a, b);

  std::cout << "abc " << a << " " << b << " " << c << " " << std::endl << std::endl;

  if(c == -1)
  {
    std::cout << "Returning UB " << UB << std::endl;
    return UB;
  }

  auto orderByR = [](Task const& left, Task const& right) { return left.r < right.r; };
  auto orderByQ = [](Task const& left, Task const& right) { return left.q < right.q; };

  auto rP = std::min_element(tasks.begin()+c+1, tasks.begin()+b+1, orderByR);
  auto qP = std::min_element(tasks.begin()+c+1, tasks.begin()+b+1, orderByQ);
  auto pP = std::accumulate(tasks.begin()+c+1, tasks.begin()+b+1, 0,
                            [](int sum, Task const& task)  {
                              return sum + task.p;
                            });
  std::cout << (*rP).r << " " << (*qP).q << " " << pP << " primy" << std::endl;
  
  auto taskC_r_Copy = tasks[c];
  tasks[c].r = std::max(tasks[c].r, (*rP).r + pP);
  auto LB = schrageWithDivision(tasks);
  std::cout << "LB z UB: " << LB << " " << UB << std::endl;
  if(LB < UB)
    calier(tasks);

  auto elem = std::find(begin(tasks), end(tasks), taskC_r_Copy);
  (*elem).r = taskC_r_Copy.r;

  auto taskC_q_Copy = tasks[c];
  tasks[c].q = std::max(tasks[c].q, (*qP).q + pP);
  LB = schrageWithDivision(tasks);
  std::cout << "2 czesc U i UB :" << U << " " << UB << std::endl;
  if(LB < UB)
    calier(tasks);

  elem = std::find(begin(tasks), end(tasks), taskC_q_Copy);
  (*elem).q = taskC_q_Copy.q;

  return UB;
}
