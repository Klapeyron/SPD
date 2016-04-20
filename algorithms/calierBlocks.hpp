#pragma once

#include <algorithm>
#include <numeric>
#include "SchrageAlgorithm.hpp"

namespace CalierBlocks
{
int calculateA(std::vector<Task> const& tasks, unsigned int b);
int calculateB(std::vector<Task> const& tasks);
int calculateC(std::vector<Task> const& tasks, unsigned int a, unsigned int b);
}
