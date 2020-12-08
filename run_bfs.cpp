/**
 * @file run_bfs.cpp
 * Uses the BFS class in an executable. 
 * This loads in an airport and route file, and then finds the shortest path
 * between a source and destination airport.
 * 
 * This file is modeled off of anagram_finder.cpp in lab_dict
 */
#include "bfs.h"
#include "loader.h"

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
using namespace traversals;

const string USAGE = 
"USAGE: ./run_bfs [AIRPORTS_FILE] [ROUTES_FILE] [SOURCE_ID] [DEST_ID]\n";

int main(int argc, char* argv[]) {
  if (argc < 5) {
    cerr << USAGE << endl;
    return -1;
  }

  vector<string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  BFS bfs;
  Graph g = createGraph(args[1], args[0]);

  vector<Vertex> path = bfs.BFS_get_path(g, args[2], args[3]);
  cout << "------------------------------------------------------" << endl;
  cout << "Path from " << g.airportMap.at(args[2]).getName() << " to " << g.airportMap.at(args[3]).getName() << ":" << endl;
  cout << endl;
  for (size_t i = 0; i < path.size() - 1; i++) {
    cout << g.airportMap.at(path[i]).getID() << " -> ";
  }
  cout << args[3] << endl;
  cout << endl;
}