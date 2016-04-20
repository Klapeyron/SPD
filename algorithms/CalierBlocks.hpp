#pragma once

#include <algorithm>
#include <numeric>
#include "SchrageAlgorithm.hpp"

namespace CalierBlocks
{
int calculateA(std::vector<Task> & tasks, unsigned int b);
int calculateB(std::vector<Task> & tasks);
int calculateC(std::vector<Task> & tasks, unsigned int a, unsigned int b);
}
