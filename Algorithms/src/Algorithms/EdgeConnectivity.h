#ifndef EDGECONNECTIVITY_H
#define EDGECONNECTIVITY_H

#include "IGraphAlgorithm.h"

class EdgeConnectivity final : public IGraphAlgorithm {
public:
  explicit EdgeConnectivity(GraphMatrix& graph) :
    IGraphAlgorithm(graph) {}

  void Execute() override;

private:
  bool IsConnected(std::vector<bool>& visited);
  void dfs(int u, std::vector<bool>& visited, std::vector<std::vector<bool>>& removed);
};



#endif //EDGECONNECTIVITY_H
