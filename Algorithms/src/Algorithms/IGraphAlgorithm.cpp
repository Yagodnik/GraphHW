#include "IGraphAlgorithm.h"

EdgeList IGraphAlgorithm::ConvertToEdgeList() {
  EdgeList edges;

  for (int i = 0; i < graph_.size(); ++i) {
    for (int j = 0; j < graph_[i].size(); ++j) {
      if (graph_[i][j] != 0) {
        edges.emplace_back(i, j);
      }
    }
  }

  return edges;
}