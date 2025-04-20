#ifndef MINIMUMVERTEXCOVER_H
#define MINIMUMVERTEXCOVER_H

#include "IGraphAlgorithm.h"

class MinimumVertexCover final : public IGraphAlgorithm {
public:
  explicit MinimumVertexCover(GraphMatrix& graph) : IGraphAlgorithm(graph) {}

  void Execute() override;

private:
  static bool IsVertexCover(const std::vector<std::pair<int, int>>& edges, const std::vector<bool>& cover);
};



#endif //MINIMUMVERTEXCOVER_H
