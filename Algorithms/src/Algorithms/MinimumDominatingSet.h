#ifndef MINIMUMDOMINATINGSET_H
#define MINIMUMDOMINATINGSET_H

#include "IGraphAlgorithm.h"

class MinimumDominatingSet final : public IGraphAlgorithm {
public:
  explicit MinimumDominatingSet(GraphMatrix& graph) :
    IGraphAlgorithm(graph) {}

  void Execute() override;

private:
  bool IsDominatingSet(int mask) const;
};



#endif //MINIMUMDOMINATINGSET_H
