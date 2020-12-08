/**
 * @file landmark.h
 */

#pragma once

#include <vector>

#include "dijkstra.h"
#include "graph.h"

using namespace std;

namespace traversals {
  class Landmark {
    public:
      // Method which finds a shortest path that goes from vertex source to vertex destination
      // and also goes through another defined vertex
      // return: the path
      vector<Vertex> landmark_path (Graph g, Vertex source, Vertex dest, Vertex landmark);
  };
}
