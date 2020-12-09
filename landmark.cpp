#include "landmark.h"

using namespace traversals;

vector<Vertex> Landmark::landmark_path (Graph g, Vertex source, Vertex dest, Vertex landmark) {
  // Ensure that all input airports are valid
  if (!g.vertexExists(source)) {
    cerr << "Source airport does not exist" << endl;
    return {};
  } 
  if (!g.vertexExists(dest)) {
    cerr << "Destination airport does not exist" << endl;
    return {};
  } 
  if (!g.vertexExists(landmark)) {
    cerr << "Landmark airport does not exist" << endl;
    return {};
  }

  Dijkstra d;
  // Run Dijkstra's from source to landmark
  vector<Vertex> source_to_landmark = d.dijkstra_path(g, source, landmark);
  if (source_to_landmark.empty()) {
    return {};
  }

  // Removes the landmark so it is not duplicated in the path
  source_to_landmark.pop_back();

  // Run Dijkstra's from landmark to destination
  vector<Vertex> landmark_to_dest = d.dijkstra_path(g, landmark, dest);
  if (landmark_to_dest.empty()) {
    return {};
  }

  // Append the two paths in order to find the shortest path from source to dest through landmark
  source_to_landmark.insert(source_to_landmark.end(), landmark_to_dest.begin(), landmark_to_dest.end());
  return source_to_landmark;  
}