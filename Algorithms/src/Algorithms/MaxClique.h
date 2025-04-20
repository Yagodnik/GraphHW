#ifndef MAXCLIQUE_H
#define MAXCLIQUE_H

#include "IGraphAlgorithm.h"

class MaxClique final : public IGraphAlgorithm {
public:
  explicit MaxClique(GraphMatrix& graph) : IGraphAlgorithm(graph) {}

  void Execute() override;
};

#endif //MAXCLIQUE_H
