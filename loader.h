#pragma once

#include "airport.h"
#include "route.h"
#include "graph.h"

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <sstream>
#include <map>
#include <math.h>  

using namespace std;

map<string, Airport> loadDataFromAirportFile(const string& filename);

vector<Route> loadDataFromRouteFile(const string& filename);

double getDistanceFromLatLong(double lat_1, double long_1, double lat_2, double long_2);

Graph createGraph();