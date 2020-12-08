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
      map<Vertex, double> dijkstra_main(Graph g, Vertex source);
      vector<Vertex> dijkstra_path(Graph g, Vertex source, Vertex dest);
      // void printToFile(string file_name);
    private:
      // map<Vertex, double> all_path_distances_;
      // Vertex source_;
  };
}