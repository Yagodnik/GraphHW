#ifndef GRAPHPARAMS_H
#define GRAPHPARAMS_H

#include "IGraphAlgorithm.h"

class GraphParams final : public IGraphAlgorithm {
public:
  explicit GraphParams(GraphMatrix& graph) :
    IGraphAlgorithm(graph) {}

  void Execute() override;

private:
  GraphMatrix floydWarshall();
  std::vector<int> FindEccentricities();
  void FindRadiusAndDiameter();
  std::vector<int> FindVertexDegrees();
  int FindMinDegree();
  void FindCenters();
};

#endif //GRAPHPARAMS_H
