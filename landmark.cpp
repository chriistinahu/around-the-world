#include "landmark.h"

using namespace traversals;

vector<Vertex> Landmark::landmark_path (Graph g, Vertex source, Vertex dest, Vertex landmark) {
  Dijkstra d;
  vector<Vertex> source_to_landmark = d.dijkstra_path(g, source, landmark);
  source_to_landmark.pop_back();
  vector<Vertex> landmark_to_dest = d.dijkstra_path(g, landmark, dest);
  source_to_landmark.insert(source_to_landmark.end(), landmark_to_dest.begin(), landmark_to_dest.end());
  return source_to_landmark;  
}