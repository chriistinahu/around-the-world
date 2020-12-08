#include <iostream>

#include "loader.h"
#include "route.h"
#include "airport.h"
#include "bfs.h"

using std::cout;
using std::endl;

const string USAGE = 
"USAGE: ./main [AIRPORTS_FILE] [ROUTES_FILE]\n";

int main(int argc, char* argv[]) {
  // run and outputs all traversals
  // argv[0] - airports.txt style filename
  // argv[1] - routes.txt style filename
  
  if (argc < 3) {
    cerr << USAGE << endl;
    return -1;
  }

  vector<string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
    cout << argv[i] << endl;
  }

  // BFS bfs;
  // Graph g = createGraph(args[0], args[1]);


  return 0;
}