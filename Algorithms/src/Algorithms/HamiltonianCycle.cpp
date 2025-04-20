#include "HamiltonianCycle.h"
#include <algorithm>
#include <iostream>

bool HamiltonianCycle::IsSafe(int v, std::vector<int>& path, int pos) const {
  if (!graph_[path[pos - 1]][v]) {
    return false;
  }

  return std::ranges::all_of(path, [&](const int elem) {
    return elem != v;
  });
}

bool HamiltonianCycle::CycleUtil(std::vector<int>& path, int pos) {
  int n = graph_.size();

  if (pos == n) {
    if (graph_[path[pos - 1]][path[0]]) {
      return true;
    }
    return false;
  }

  for (int v = 1; v < n; ++v) {
    if (IsSafe(v, path, pos)) {
      path[pos] = v;

      if (CycleUtil(path, pos + 1)) {
        return true;
      }

      path[pos] = -1;
    }
  }

  return false;
}

void HamiltonianCycle::Execute() {
  int n = graph_.size();
  std::vector<int> path(n, -1);

  path[0] = 0;

  if (!CycleUtil(path, 1)) {
    std::cout << "No Hamiltonian Cycle found" <<std:: endl;
    return;
  }

  std::cout << "Hamiltonian Cycle: ";
  for (int i = 0; i < n; ++i) {
    std::cout << path[i] + 1 << " ";
  }
  std::cout << std::endl;
}