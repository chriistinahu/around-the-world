#include "loader.h"

/// Create map of airport id to airport object from csv file of airport data
map<string, Airport> loadDataFromAirportFile(const string& filename) {
  ifstream text(filename);
  map<string, Airport> airports;
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
    Airport airport(info.at(0), info.at(1), info.at(3), stod(info.at(6)), stod(info.at(7)));
    airports.insert(pair<string, Airport>(info.at(0), airport));
  }
  return airports;
}

/// Create vector of Route objects from csv file of route data
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
  }
	return routes;

}

double getDistanceFromLatLong(double lat_1, double long_1, double lat_2, double long_2) {
  // using haversine formula
  float pi = 0.017453292519943295;    // Math.PI / 180
  float a = 0.5 - cos((lat_2 - lat_1) * pi)/2 + 
          cos(lat_1 * pi) * cos(lat_2 * pi) * 
          (1 - cos((long_2 - long_1) * pi))/2;

  // RETURNS IN KILOMETERS!!!
  return 12742 * asin(sqrt(a)); // 2 * R; R = 6371 km 
}

/// Create a graph object representing airports and their routes to one another
/// vertices hold airport id
/// directed edges represent that there is a route from an airport to another airport
/// edge weights represent distance of the route from airport to another airport
Graph createGraph(string routes_file, string airports_file) {

  vector<Route> routes = loadDataFromRouteFile(routes_file);
  map<string, Airport> airports = loadDataFromAirportFile(airports_file);

  Graph graph(true, true);

  // traverse the routes vector
  //    from each route object, get airport id
  //    using airport id, get airport object
  // create vertices/ find vertices
  // connect verices -- create edge
  // find distance
  // set edge weight

  for (Route route : routes) {
    string source_port_id = route.getSrcAirport();
    string dest_port_id = route.getDestAirport();
    
    if (!graph.vertexExists(source_port_id)) {
      graph.insertVertex(source_port_id);   
    } 
    if (!graph.vertexExists(dest_port_id)) {
      graph.insertVertex(dest_port_id);
    }

    graph.insertEdge(source_port_id, dest_port_id);
    Airport source_port = airports.at(source_port_id);
    Airport dest_port = airports.at(dest_port_id);
    double dist = getDistanceFromLatLong(source_port.getLatitude(), source_port.getLongitude(),
                                         dest_port.getLatitude(), dest_port.getLongitude());
    graph.setEdgeWeight(source_port_id, dest_port_id, dist);
  }
  return graph;
}