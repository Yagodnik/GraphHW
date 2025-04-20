#include "MaxClique.h"

#include <iostream>
#include <ostream>

void MaxClique::Execute() {
  int n = graph_.size();
  int best_size = 0;
  int best_mask = 0;

  int total_masks = (1 << n);
  for (int mask = 1; mask < total_masks; ++mask) {
    bool is_clique = true;

    for (int i = 0; i < n && is_clique; ++i) {
      if (!(mask & (1 << i))) continue;
      for (int j = i + 1; j < n; ++j) {
        if ((mask & (1 << j)) && !graph_[i][j]) {
          is_clique = false;
          break;
        }
      }
    }

    if (is_clique) {
      int count = __builtin_popcount(mask);
      if (count > best_size) {
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

  std::cout << "Max Clique: ";
  for (int i = 0; i < result.size(); ++i)
    std::cout << result[i] << " ";
  std::cout << std::endl;
}
