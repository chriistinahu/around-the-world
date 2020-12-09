/**
 * @file landmark.h
 */

#pragma once

#include <vector>

#include "dijkstra.h"
#include "graph.h"

using namespace std;

namespace traversals {
  /**
   * The Landmark class allows the user to run the Landmark algorithm on a graph to find the 
   * shortest distance from source airport to destination airport through a landmark airport. 
   * 
   * This class does use the edge weights of the Graph, 
   * so the shortest path is defined by the distance between airports in km.
   */
  class Landmark {
    public:
      /**
       * Inputs: the Graph to traverse on, the source, destination, and landmark airport IATA codes
       * Output: a vector of Vertices that represents the shortest path from source to destination through landmark
       */
      vector<Vertex> landmark_path (Graph g, Vertex source, Vertex dest, Vertex landmark);
  };
}
