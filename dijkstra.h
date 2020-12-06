/**
 * @file Dijkstra.h
 */

#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <map>
#include <iostream>
#include <vector>

#include "graph.h"

using namespace std;

namespace traversals {
  class Dijkstra {
    public:
      void dijkstra_main(Graph g, Vertex source);


    private:
      double min_distance();
      const int INF = INT_MAX;
      map<Vertex, bool> visted_vertices; // keep track of vertice status
  };
}