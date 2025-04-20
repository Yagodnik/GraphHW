#ifndef VERTEX_CONNECTIVITY_H
#define VERTEX_CONNECTIVITY_H

#include "IGraphAlgorithm.h"

class VertexConnectivity final : public IGraphAlgorithm {
public:
  explicit VertexConnectivity(GraphMatrix& graph) :
    IGraphAlgorithm(graph) {}

  void Execute() override;

private:
  bool IsConnected(std::vector<bool>& visited);
  void dfs(int u, std::vector<bool>& visited, std::vector<bool>& removed);
  int FindVertexConnectivity();
};


#endif // VERTEX_CONNECTIVITY_H
