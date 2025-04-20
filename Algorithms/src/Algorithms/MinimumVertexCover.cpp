#include "MinimumVertexCover.h"
#include <iostream>
#include <algorithm>

bool MinimumVertexCover::IsVertexCover(const std::vector<std::pair<int, int>>& edges, const std::vector<bool>& cover) {
  return std::ranges::all_of(edges, [&](const auto& edge) {
    const auto& [u, v] = edge;
    return cover[u] || cover[v];
  });
}

void MinimumVertexCover::Execute() {
  const EdgeList edges = ConvertToEdgeList();

  int minSize =  std::numeric_limits<int>::max();
  const int n = graph_.size();

  std::vector<int> minimal_cover;
  for (int mask = 0; mask < (1 << n); ++mask) {
    std::vector<bool> cover(n, false);
    for (int i = 0; i < n; ++i) {
      cover[i] = mask & (1 << i);
    }

    if (IsVertexCover(edges, cover)) {
      int count = __builtin_popcount(mask);

      if (count < minSize) {
        minSize = count;
        minimal_cover.clear();

        int index = 0;
        std::ranges::for_each(cover, [&](bool value) {
          if (value) {
            minimal_cover.push_back(index);
          }

          index++;
        });
      }
    }
  }

  std::cout << "Minimal vertex cover: ";
  std::ranges::for_each(minimal_cover, [&](int vertex) {
    std::cout << vertex + 1 << " ";
  });
  std::cout << std::endl;
}
