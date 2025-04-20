#ifndef HAMILTONIANCYCLE_H
#define HAMILTONIANCYCLE_H

#include "IGraphAlgorithm.h"

class HamiltonianCycle : IGraphAlgorithm {
public:
  explicit HamiltonianCycle(GraphMatrix& graph) :
      IGraphAlgorithm(graph) {}

  void Execute() override;

private:
  bool IsSafe(int v, std::vector<int>& path, int pos) const;
  bool CycleUtil(std::vector<int>& path, int pos);
};


#endif //HAMILTONIANCYCLE_H
