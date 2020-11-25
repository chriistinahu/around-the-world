#include "airport.h"
#include "route.h"

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

vector<Airport> loadDataFromAirportFile(const string& filename) {
  ifstream text(filename);
  vector<Airport> airports;
  string line;
  while(getline(text, line)) {
    vector<string> info;
    string field;
    for (size_t i = 0; i < line.size() - 1; i++) {
      if (line[i] == ',' && line[i + 1] != ' ') {
        info.push_back(field);
        field = "";
      } else {
        field += line[i];
      }
    }
    Airport airport(stoi(info.at(0)), info.at(1), info.at(3), stod(info.at(6)), stod(info.at(7)));
    airports.push_back(airport);
  }
  return airports;
}

vector<Route> loadDataFromRouteFile(const string& filename) {
  ifstream text(filename);
  vector<Route> routes;
  string line;
  while(getline(text, line)) {
    vector<string> info;
    string field;
    stringstream ss(line);
    while (getline(ss, field, ',')) {
      info.push_back(field);
    }

    Route route(info.at(3), info.at(5));
    routes.push_back(route);
    cout << info.at(3) << endl;
  }
	return routes;

}