cmake_minimum_required(VERSION 3.29)
project(Graphpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(Graphpp src/main.cpp
        src/Graph.cpp
        src/Algorithms/IGraphAlgorithm.cpp
        src/Algorithms/MaxClique.cpp
        src/Algorithms/MinimumVertexCover.cpp
        src/Algorithms/MinimumEdgeCover.cpp
        src/Algorithms/MinimumDominatingSet.cpp
        src/Algorithms/MaxStableSet.cpp
        src/Algorithms/GraphParams.cpp
        src/Algorithms/VertexConnectivity.cpp
        src/Algorithms/VertexConnectivity.h
        src/Algorithms/EdgeConnectivity.cpp
        src/Algorithms/EdgeConnectivity.h
        src/Algorithms/HamiltonianCycle.h
        src/Algorithms/HamiltonianCycle.cpp
        src/Algorithms/EulerianCycle.cpp
        src/Algorithms/EulerianCycle.h)
