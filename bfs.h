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
  /**
   * The BFS class allows the user to run a BFS on a graph to find the 
   * shortest path from a source to a destination airport. 
   * 
   * BFS does not use edge weights. 
   * So, the shortest distance is defined by the number of stops, not the distance in km.
   */
  class BFS {
    public:
      /**
       * Inputs: the Graph to traverse on, the source airport's IATA code, and the destination airport's IATA code
       * Output: a vector of Vertices that represents the shortest path from the source to the destination airport
       */
      vector<Vertex> BFS_get_path(Graph g, Vertex source, Vertex dest);

    private:
        // Keeps track of which vertices have been explored
        map<Vertex, bool> explored_vertices;
  };
}
