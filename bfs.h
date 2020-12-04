/**
 * @file BFS.h
 */

#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <map>
#include <iostream>

#include "graph.h"

using namespace std;

namespace traversals {
  class BFS {
    public:
      void BFS_main (Graph g);

      // traverses whole graph starting from one vertex
      void BFS_whole(Graph g, Vertex v);

      // uses BFS to find a destination in graph
      vector<Vertex> BFS_get_path(Graph g, Vertex source, Vertex dest);

    private:
        map<Vertex, bool> explored_vertices; // keep track of vertice status
  };
}
