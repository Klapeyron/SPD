#include "CalierAlgorithm.hpp"

int calier(std::vector<Task> & tasks)
{
  int UB = std::numeric_limits<int>::max();
  int U = schrage(tasks);
  if(U < UB)
    UB = U;

  int b = CalierBlocks::calculateB(tasks, UB);
  int a = CalierBlocks::calculateA(tasks, b, UB);
  int c = CalierBlocks::calculateC(tasks, a, b);

  auto orderByR = [](Task const& left, Task const& right) { return left.r < right.r; };
  auto orderByQ = [](Task const& left, Task const& right) { return left.q < right.q; };

  auto rP = std::min_element(tasks.begin()+c+1, tasks.begin()+b, orderByR);
  auto qP = std::min_element(tasks.begin()+c+1, tasks.begin()+b, orderByQ);
  auto pP = std::accumulate(tasks.begin() + c + 1, tasks.begin() + b, 0,
                            [](int sum, Task const& task)  {
                              return sum + task.p;
                            });
  auto taskC_r_Copy = tasks[c].r;
  tasks[c].r = std::max(tasks[c].r, (*rP).r + pP);
  auto LB = schrageWithDivision(tasks);
  if(LB < UB)
    calier(tasks);

  tasks[c].r = taskC_r_Copy;

  auto taskC_q_Copy = tasks[c].q;
  tasks[c].q = std::max(tasks[c].q, (*qP).q + pP);
  LB = schrageWithDivision(tasks);
  if(LB < UB)
    calier(tasks);

  tasks[c].q = taskC_q_Copy;

  return UB;
}
