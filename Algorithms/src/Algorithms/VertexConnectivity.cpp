#include "VertexConnectivity.h"

#include <iostream>
#include <ostream>

void VertexConnectivity::Execute() {
  std::cout << "VertexConnectivity: " << FindVertexConnectivity() << std::endl;
}

bool VertexConnectivity::IsConnected(std::vector<bool>& visited) {
  const int n = visited.size();
  int visitedCount = 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i]) {
      visitedCount++;
    }
  }
  return visitedCount == n;
}

void VertexConnectivity::dfs(int u, std::vector<bool>& visited, std::vector<bool>& removed) {
  visited[u] = true;
  for (int v : graph_[u]) {
    if (!visited[v] && !removed[v]) {
      dfs(v, visited, removed);
    }
  }
}

int VertexConnectivity::FindVertexConnectivity() {
  const int n = graph_.size();
  int minConnectivity = n;

  for (int mask = 1; mask < (1 << n); ++mask) {
    std::vector<bool> removed(n, false);
    std::vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        removed[i] = true;
      }
    }

    dfs(0, visited, removed);
    if (!IsConnected(visited)) {
      int removedCount = __builtin_popcount(mask);
      minConnectivity = std::min(minConnectivity, removedCount);
    }
  }

  return minConnectivity;
}