#ifndef EULERIANCYCLE_H
#define EULERIANCYCLE_H

#include "IGraphAlgorithm.h"

class EulerianCycle : IGraphAlgorithm {
public:
  EulerianCycle(GraphMatrix& graph) :
      IGraphAlgorithm(graph) {}

  void Execute() override;
};



#endif //EULERIANCYCLE_H
