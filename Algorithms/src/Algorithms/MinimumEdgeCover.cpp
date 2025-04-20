#include "MinimumEdgeCover.h"

#include <iostream>
#include <algorithm>

bool MinimumEdgeCover::IsEdgeCover(EdgeList& edge_list) {
  int n = graph_.size();
  std::vector<bool> covered(n, false);

  for (const auto& edge : edge_list) {
    int u = edge.first;
    int v = edge.second;
    covered[u] = true;
    covered[v] = true;
  }

  return std::ranges::all_of(covered, [](bool vertexCovered) { return vertexCovered; });
}

void MinimumEdgeCover::Execute() {
  EdgeList edges = ConvertToEdgeList();
  int total_edges = edges.size();

  int min_edge_count = std::numeric_limits<int>::max();
  std::vector<std::pair<int, int>> min_edge_set;

  int num_subsets = 1 << total_edges;
  for (int i = 1; i < num_subsets; i++) {
    std::vector<std::pair<int, int>> edgeSet;

    for (int j = 0; j < total_edges; j++) {
      if (i & (1 << j)) {
        edgeSet.push_back(edges[j]);
      }
    }

    if (IsEdgeCover(edgeSet) && edgeSet.size() < min_edge_count) {
      min_edge_count = edgeSet.size();
      min_edge_set = edgeSet;
    }
  }

  std::cout << "Minimum edge cover: " << std::endl;
  for (int i = 0; i < min_edge_count; i++) {
    std::cout << min_edge_set[i].first + 1 << " " << min_edge_set[i].second + 1 << std::endl;
  }
}
