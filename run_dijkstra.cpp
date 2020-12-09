#include "dijkstra.h"
#include "loader.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <map>

using namespace std;
using namespace traversals;

const string USAGE = 
"USAGE: ./run_dijkstra [AIRPORTS_FILE] [ROUTES_FILE] [SOURCE_ID] [DEST_ID]\n";

int main(int argc, char* argv[]) {
  if (argc < 5) {
    cerr << USAGE << endl;
    return -1;
  }

  vector<string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  ifstream routes_file(args[1]);
  ifstream airports_file(args[0]);

  if (!routes_file) {
    cerr << "Route file does not exist" << endl;
    return EXIT_FAILURE;
  }

  if (!airports_file) {
    cerr << "Airport file does not exist" << endl;
    return EXIT_FAILURE;
  }

  Dijkstra d;
  Graph g = createGraph(args[1], args[0]);

  map<Vertex, double> all_paths = d.dijkstra_main(g, args[2]);
  std::cout << "\nSource Airport: " << args[2] << std::endl;
  std::cout << "Shortest distances from source to airports: " << std::endl;
  map<Vertex, double>::iterator it;
  for (it = all_paths.begin(); it != all_paths.end(); it++) {
    std::cout << "  " << it->first << " | " << it->second << " km" << std::endl;
  }
  vector<Vertex> path = d.dijkstra_path(g, args[2], args[3]);
  cout << "------------------------------------------------------" << endl;
  cout << "Path from " << g.airportMap.at(args[2]).getName() << " to " << g.airportMap.at(args[3]).getName() << ":" << endl;
  cout << endl;
  if (path.empty()) {
    cout << "Path does not exist" << endl;
  } else {
    for (size_t i = 0; i < path.size() - 1; i++) {
      cout << g.airportMap.at(path[i]).getID() << " -> ";
    }
    cout << args[3] << endl;
    cout << endl;
    }
}