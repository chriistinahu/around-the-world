#include <iostream>

#include "loader.h"
#include "route.h"
#include "airport.h"
#include "bfs.h"
#include "dijkstra.h"
#include "landmark.h"

using namespace std;
using namespace traversals;

const string USAGE = 
"USAGE: ./main <AIRPORTS_FILE> <ROUTES_FILE> <SOURCE> <DEST> <LANDMARK>\n";

int main(int argc, char* argv[]) {
  // run and outputs all traversals
  // argv[0] - airports.txt style filename
  // argv[1] - routes.txt style filename
  // argv[2] - source
  // argv[3] - dest
  // argv[4] - landmark
  if (argc < 6) {
    cerr << USAGE << endl;
    return -1;
  }

  vector<string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  BFS bfs;
  Graph g = createGraph(args[1], args[0]);
  Vertex source_ = args[2];
  Vertex dest_ = args[3];

  vector<Vertex> path = bfs.BFS_get_path(g, source_, dest_);
  cout << "___________________________________________________________________________" << endl;
  cout << "\n---- BFS - FIND SHORTEST PATH FROM " << source_ << " TO " << dest_ << " ----"<<endl;
  cout << "Path from " << g.airportMap.at(source_).getName() << " to " << g.airportMap.at(dest_).getName() << ":" << endl;
  cout << endl;
  for (size_t i = 0; i < path.size() - 1; i++) {
    cout << g.airportMap.at(path[i]).getID() << " -> ";
  }
  cout << dest_ << endl;
  cout << endl;

  cout << "___________________________________________________________________________" << endl;
  cout << "\n---- DIJKSTRAS - FIND SHORTEST PATH FROM " << source_ << " TO ALL CONNECTIONS" << " ----" << endl;
  Dijkstra d;
  map<Vertex, double> all_paths = d.dijkstra_main(g, source_);
  cout << "\nSource Airport: " << source_ << endl;
  cout << "Shortest distances from source to airports: " << endl;
  map<Vertex, double>::iterator it;
  for (it = all_paths.begin(); it != all_paths.end(); it++) {
    cout << "  " << it->first << " | " << it->second << " km" << endl;
  }
  path = d.dijkstra_path(g, source_, dest_);
  cout << "___________________________________________________________________________" << endl;
  cout << "\n---- DIJKSTRAS - FIND SHORTEST PATH FROM " << source_ << " TO " << dest_ << " ----" << endl;;
  cout << "Path from " << g.airportMap.at(source_).getName() << " to " << g.airportMap.at(dest_).getName() << ":" << endl;
  cout << endl;
  for (size_t i = 0; i < path.size() - 1; i++) {
    cout << g.airportMap.at(path[i]).getID() << " -> ";
  }
  cout << dest_ << endl;
  cout << endl;

  cout << "___________________________________________________________________________" << endl;
  cout << "\n---- LANDMARK - FIND SHORTEST PATH FROM " << source_ <<  " TO " << dest_ << " PASSING THROUGH " << args[4] << " ----"<<endl;
  Landmark l;
  path = l.landmark_path(g, source_, dest_, args[4]);
  cout << "Path from " << g.airportMap.at(source_).getName() << " to " << g.airportMap.at(args[4]).getName() << " to " << g.airportMap.at(dest_).getName() << ":" << endl;
  cout << endl;
  for (size_t i = 0; i < path.size() - 1; i++) {
    cout << g.airportMap.at(path[i]).getID() << " -> ";
  }
  cout << dest_ << endl;
  cout << endl;
  cout << "You have successfully run all our traversals, have a safe flight!" << endl;
  return 0;
}