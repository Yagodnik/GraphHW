#ifndef IGRAPHALGORITHM_H
#define IGRAPHALGORITHM_H

#include <vector>

using GraphMatrix = std::vector<std::vector<int>>;
using EdgeList = std::vector<std::pair<int, int>>;

class IGraphAlgorithm {
public:
  explicit IGraphAlgorithm(GraphMatrix &graph) : graph_(graph) {}
  virtual ~IGraphAlgorithm() {}

  virtual void Execute() = 0;
  EdgeList ConvertToEdgeList();

protected:
  GraphMatrix &graph_;
};

#endif //IGRAPHALGORITHM_H
