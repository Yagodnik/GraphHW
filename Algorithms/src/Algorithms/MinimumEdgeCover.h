#pragma once

#include <vector>

#include "IGraphAlgorithm.h"

class MinimumEdgeCover : IGraphAlgorithm {
public:
  explicit MinimumEdgeCover(GraphMatrix& graph) :
    IGraphAlgorithm(graph) {}

  void Execute();

private:
  bool IsEdgeCover(EdgeList& edge_list);
};
