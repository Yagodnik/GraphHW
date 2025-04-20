#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool Graph::LoadFromAdjacencyMatrix(const std::string &path) {
  std::ifstream graph_file(path);
  if (!graph_file.is_open()) {
     std::cerr << "Unable to open file " << path << std::endl;
     return false;
  }
  std::string line;

  graph_.clear();
  while (std::getline(graph_file, line, '\n')) {
    graph_.emplace_back();
    if (!Graph::ParseLine(line, graph_.back())) {
      return false;
    }
  }

  return true;
}

bool Graph::ParseLine(const std::string &line, std::vector<int> &data) {
  std::stringstream ss(line);
  std::string token;

  while (std::getline(ss, token, ',')) {
    std::size_t start = token.find_first_not_of(" \t");
    std::size_t end = token.find_last_not_of(" \t");

    if (start != std::string::npos && end != std::string::npos) {
      std::string trimmed = token.substr(start, end - start + 1);
      try {
        data.push_back(std::stoi(trimmed));
      } catch (...) {
        std::cerr << "Invalid data format in: " << line << std::endl;
        return false;
      }
    }
  }

  return true;
}

void Graph::NameVertices(std::vector<std::string> &titles) {
  vertex_titles_.clear();
  vertex_titles_.reserve(titles.size());

  for (const auto &title : titles) {
    vertex_titles_.emplace_back(title);
  }
}

void Graph::PrintAdjacencyMatrix(std::ostream &stream) const {
  for (const auto &row : graph_) {
    for (const auto &col : row) {
      stream << col << " ";
    }
    stream << std::endl;
  }
}

std::string Graph::VertexName(int index) const {
  return (!vertex_titles_.empty()) ? vertex_titles_[index] : std::to_string(index);
}