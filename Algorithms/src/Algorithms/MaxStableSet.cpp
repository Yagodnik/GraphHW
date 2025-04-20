#include "MaxStableSet.h"

#include <iostream>
#include <ostream>
#include <set>

bool MaxStableSet::IsIndependentSet(int mask) const {
  const int n = graph_.size();

  for (int u = 0; u < n; ++u) {
    if (!(mask & (1 << u))) {
      continue;
    }

    for (int v = u + 1; v < n; ++v) {
      if (!(mask & (1 << v))) {
        continue;
      }

      if (graph_[u][v]) {
        return false;
      }
    }
  }
  return true;
}

void MaxStableSet::Execute() {
  const int n = graph_.size();
  int best_mask = 0;
  int best_size = 0;

  for (int mask = 0; mask < (1 << n); ++mask) {
    int size = __builtin_popcount(mask);
    if (size <= best_size) continue;

    if (IsIndependentSet(mask)) {
      best_size = size;
      best_mask = mask;
    }
  }

  std::set<int> result;
  for (int i = 0; i < n; ++i) {
    if (best_mask & (1 << i)) {
      result.insert(i);
    }
  }

  std::cout << "MaxStableSet: ";
  for (auto v : result) {
    std::cout << v + 1 << " ";
  }
  std::cout << std::endl;
}