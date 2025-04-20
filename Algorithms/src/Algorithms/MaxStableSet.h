#ifndef MAXSTABLESET_H
#define MAXSTABLESET_H

#include "IGraphAlgorithm.h"

class MaxStableSet final : public IGraphAlgorithm {
public:
  explicit MaxStableSet(GraphMatrix& graph) :
    IGraphAlgorithm(graph) {}

  void Execute() override;

private:
  bool IsIndependentSet(int mask) const;
};

#endif //MAXSTABLESET_H
