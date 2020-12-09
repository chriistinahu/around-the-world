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
  /**
   * The Dijkstra class allows the user to run the Dijkstra algorithm on a graph to find the 
   * shortest distance from source airport to all other airports, 
   * as well as find the shortest path from a source to a destination airport. 
   * 
   * Dijkstra's does use the edge weights of the Graph,
   * so the shortest path is defined by the distance between airports in km.
   */
  class Dijkstra {
    public:
      /**
       * Inputs: the Graph to traverse on, the source airport's IATA code
       * Output: a map that maps each Vertex on the Graph to it's shortest distance from the source airport
       */
      map<Vertex, double> dijkstra_main(Graph g, Vertex source);

      /**
       * Inputs: the Graph to traverse on, the source and destination airports' IATA code
       * Output: a vector of Vertices that represents the shortest path from source to destination airport
       */
      vector<Vertex> dijkstra_path(Graph g, Vertex source, Vertex dest);
  };
}