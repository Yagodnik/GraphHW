#include "MinimumDominatingSet.h"

#include <iostream>
#include <set>

void MinimumDominatingSet::Execute() {
  int n = graph_.size();
  int best_size = n + 1;
  int best_mask = 0;

  std::vector<int> neighbor_mask(n, 0);
  for (int i = 0; i < n; ++i) {
    neighbor_mask[i] = (1 << i);
    for (int j = 0; j < n; ++j) {
      if (graph_[i][j])
        neighbor_mask[i] |= (1 << j);
    }
  }

  int totalMasks = (1 << n);
  for (int mask = 1; mask < totalMasks; ++mask) {
    int covered = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i))
        covered |= neighbor_mask[i];
    }

    if (covered == (1 << n) - 1) {
      int count = __builtin_popcount(mask);
      if (count < best_size) {
        best_size = count;
        best_mask = mask;
      }
    }
  }

  std::vector<int> result;
  for (int i = 0; i < n; ++i) {
    if (best_mask & (1 << i)) {
      result.push_back(i + 1);
    }
  }

  std::cout << "Dominating set: ";
  for (int v : result) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}
