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

/**
 * Reads in the airport csv file
 * Inputs: name of the csv file
 * Outputs: returns a map that maps from the airport id to the Aiport object for each airport in the file
*/
map<string, Airport> loadDataFromAirportFile(const string& filename);

/**
 * Reads in the route csv file
 * Inputs: name of the csv file
 * Outputs: returns a vector of Route objects, one for each route in the file
 */
vector<Route> loadDataFromRouteFile(const string& filename);

/**
 * Calculates the distance between two latitude and longitude coordinates using the Haversine formula
 * Inputs: the latitude and longitudes for two locations
 * Outputs: returns the distance in Kilometers between the two locations
 */
double getDistanceFromLatLong(double lat_1, double long_1, double lat_2, double long_2);

/**
 * Creates a graph using the route and airports csv files
 * Inputs: routes and airports csv files
 * Outputs: returns a Graph object representing airports and their routes to one another
 */
Graph createGraph(string routes_file, string airports_file);