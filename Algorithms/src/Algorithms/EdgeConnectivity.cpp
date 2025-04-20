#include "EdgeConnectivity.h"

#include <iostream>
#include <ostream>

void EdgeConnectivity::Execute() {
  int n = graph_.size();
  std::vector<std::vector<int>> g = graph_;
  std::vector<int> vertex(n);
  for (int i = 0; i < n; ++i) {
    vertex[i] = i;
  }

  int min_cut = std::numeric_limits<int>::max();

  while (n > 1) {
    std::vector<int> w(n, 0);
    std::vector<bool> used(n, false);

    int prev = 0;
    int last = 0;

    for (int i = 0; i < n; ++i) {
      int select = -1;
      for (int j = 0; j < n; ++j) {
        if (!used[j] && (select == -1 || w[j] > w[select])) {
          select = j;
        }
      }

      if (i == n - 1) {
        min_cut = std::min(min_cut, w[select]);

        for (int j = 0; j < n; ++j) {
          g[prev][j] += g[select][j];
          g[j][prev] = g[prev][j];
        }

        vertex.erase(vertex.begin() + select);
        g.erase(g.begin() + select);
        for (auto& row : g) {
          row.erase(row.begin() + select);
        }

        --n;
        break;
      }

      used[select] = true;
      prev = last;
      last = select;

      for (int j = 0; j < n; ++j) {
        if (!used[j]) {
          w[j] += g[select][j];
        }
      }
    }
  }

  std::cout << "Edge connectivity: " << min_cut << std::endl;
}
