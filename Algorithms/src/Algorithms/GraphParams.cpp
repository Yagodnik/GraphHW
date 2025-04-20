#include "GraphParams.h"
#include <iostream>
#include <__algorithm/ranges_count.h>

void GraphParams::Execute() {
  FindRadiusAndDiameter();

  std::vector<int> degrees = FindVertexDegrees();
  FindCenters();

  std::cout << "Vertex Degrees: ";
  for (int degree : degrees) {
    std::cout << degree << " ";
  }
  std::cout << std::endl;

  std::cout << "Minimum Degree: " << FindMinDegree() << std::endl;
}

GraphMatrix GraphParams::floydWarshall() {
  const int n = graph_.size();
  GraphMatrix dist(n, std::vector<int>(n, std::numeric_limits<int>::max()));

  for (int i = 0; i < n; ++i) {
    dist[i][i] = 0;
  }
  for (int u = 0; u < n; ++u) {
    for (int v : graph_[u]) {
      if (v > 0) {
        dist[u][v] = 1;
        dist[v][u] = 1;
      }
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
          dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  return dist;
}

std::vector<int> GraphParams::FindEccentricities() {
  const int n = graph_.size();
  std::vector<int> eccentricity(n, 0);
  GraphMatrix dist = floydWarshall();

  std::cout << "Eccentricity: ";
  for (int i = 0; i < n; ++i) {
    eccentricity[i] = *std::max_element(dist[i].begin(), dist[i].end());

    std::cout << "e(" << i << ") = " << eccentricity[i] << "; ";
  }
  std::cout << std::endl;

  return eccentricity;
}

void GraphParams::FindRadiusAndDiameter() {
  std::vector<int> eccentricity = FindEccentricities();
  int radius = *std::min_element(eccentricity.begin(), eccentricity.end());
  int diameter = *std::max_element(eccentricity.begin(), eccentricity.end());

  std::cout << "Radius: " << radius << std::endl;
  std::cout << "Diameter: " << diameter << std::endl;
}

std::vector<int> GraphParams::FindVertexDegrees() {
  const int n = graph_.size();
  std::vector<int> degrees(n, 0);
  for (int i = 0; i < n; ++i) {
    degrees[i] = std::ranges::count(graph_[i], 1);
  }

  return degrees;
}

int GraphParams::FindMinDegree() {
  std::vector<int> degrees = FindVertexDegrees();
  return *std::min_element(degrees.begin(), degrees.end());
}

void GraphParams::FindCenters() {
  const int n = graph_.size();
  std::vector<int> eccentricity = FindEccentricities();
  int minEccentricity = *std::min_element(eccentricity.begin(), eccentricity.end());

  std::cout << "Centers: ";
  for (int i = 0; i < n; ++i) {
    if (eccentricity[i] == minEccentricity) {
      std::cout << i + 1 << " ";
    }
  }

  std::cout << std::endl;
}
