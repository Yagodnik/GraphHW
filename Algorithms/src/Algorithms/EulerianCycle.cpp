#include "EulerianCycle.h"

#include <iostream>

void EulerianCycle::Execute() {
  int n = graph_.size();
  GraphMatrix adj = graph_;
  std::stack<int> curr_path;
  std::vector<int> circuit;

  curr_path.push(0);

  while (!curr_path.empty()) {
    int u = curr_path.top();
    bool found = false;

    for (int v = 0; v < n; ++v) {
      if (adj[u][v] > 0) {
        adj[u][v]--;
        adj[v][u]--;
        curr_path.push(v);
        found = true;
        break;
      }
    }

    if (!found) {
      circuit.push_back(u);
      curr_path.pop();
    }
  }

  std::cout << "Eulerian Cycle: ";
  for (int i = circuit.size() - 1; i >= 0; --i) {
    std::cout << circuit[i] + 1 << " ";
  }
  std::cout << std::endl;
}
