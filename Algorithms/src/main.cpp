#include <iostream>
#include "Graph.h"

#include "Algorithms/MaxClique.h"
#include "Algorithms/MaxStableSet.h"
#include "Algorithms/MinimumVertexCover.h"
#include "Algorithms/MinimumEdgeCover.h"
#include "Algorithms/MinimumDominatingSet.h"
#include "Algorithms/MaxStableSet.h"
#include "Algorithms/GraphParams.h"
#include "Algorithms/VertexConnectivity.h"
#include "Algorithms/EdgeConnectivity.h"
#include "Algorithms/HamiltonianCycle.h"
#include "Algorithms/EulerianCycle.h"

int main() {
  Graph graph;
  if (!graph.LoadFromAdjacencyMatrix("../testdata/graph1.txt")) {
    std::cerr << "Failed to load graph from adjacency matrix" << std::endl;
    return -1;
  }

  graph.PrintAdjacencyMatrix(std::cout);
  graph.ExecuteAlgorithm<MaxClique>();
  graph.ExecuteAlgorithm<MinimumVertexCover>();
  graph.ExecuteAlgorithm<MinimumEdgeCover>();
  graph.ExecuteAlgorithm<MinimumDominatingSet>();
  graph.ExecuteAlgorithm<MaxStableSet>();
  graph.ExecuteAlgorithm<GraphParams>();
  graph.ExecuteAlgorithm<VertexConnectivity>();
  graph.ExecuteAlgorithm<EdgeConnectivity>();
  graph.ExecuteAlgorithm<HamiltonianCycle>();
  graph.ExecuteAlgorithm<EulerianCycle>();

  return 0;
}
