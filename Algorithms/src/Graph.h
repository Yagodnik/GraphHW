#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Algorithms/IGraphAlgorithm.h"

class Graph {
public:
  Graph() = default;

  bool LoadFromAdjacencyMatrix(const std::string &path);
  void NameVertices(std::vector<std::string> &titles);
  void PrintAdjacencyMatrix(std::ostream &stream) const;

  template<typename T> requires std::is_base_of_v<IGraphAlgorithm, T>
  void ExecuteAlgorithm() {
    T algorithm(graph_);
    algorithm.Execute();
  }

private:
  static bool ParseLine(const std::string &line, std::vector<int> &data);
  [[nodiscard]] std::string VertexName(int index) const;

  int vertex_count_{};
  int edge_count_{};
  std::vector<std::string> vertex_titles_;
  std::vector<std::vector<int>> graph_;
};



#endif //GRAPH_H
