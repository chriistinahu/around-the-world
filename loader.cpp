#include "loader.h"

/// Create map of airport id to airport object from csv file of airport data
map<string, Airport> loadDataFromAirportFile(const string& filename) {
  ifstream text(filename);
  if (!text) {
    cerr << "Airport file does not exist" << endl;
    return {};
  }

  map<string, Airport> airports;
  string line;
  while(getline(text, line)) {
    vector<string> info;
    string field;

    // Loops through each character to manually deliminate by commas
    // and find each field of info since some airport names contain commas
    for (size_t i = 0; i < line.size() - 1; i++) {
      if (line[i] == ',' && line[i + 1] != ' ') {
        info.push_back(field);
        field = "";
      } else {
        field += line[i];
      }
    }
    string airport_id = info.at(4);

    // Remove extra quotation marks
    airport_id.erase(remove(airport_id.begin(), airport_id.end(), '"'), airport_id.end());

    // Create new Airport object with necessary info and add to map
    Airport airport(airport_id, info.at(1), info.at(3), stod(info.at(6)), stod(info.at(7)));
    airports.insert(pair<string, Airport>(airport_id, airport));
  }
  return airports;
}

/// Create vector of Route objects from csv file of route data
vector<Route> loadDataFromRouteFile(const string& filename) {
  ifstream text(filename);
  if (!text) {
    cerr << "Route file does not exist" << endl;
    return {};
  }
  vector<Route> routes;
  string line;
  while(getline(text, line)) {
    vector<string> info;
    string field;
    stringstream ss(line);
    while (getline(ss, field, ',')) {
      info.push_back(field);
    }

    // Creates new Route object with necessary info and adds to vector
    Route route(info.at(2), info.at(4));
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

  // return value is in km
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
  // TODO: Handle invalid file, terminate running process.
  // HANDLE tmpHandle = OpenProcess(PROCESS_ALL_ACCESS, TRUE, dwProcessID);
  // if (routes.empty() || airports.empty()) {
  //   TerminateProcess(tmpHandle, 0);
  //   return graph;
  // }

  graph.airportMap = airports;
  for (Route route : routes) {
    string source_port_id = route.getSrcAirport();
    string dest_port_id = route.getDestAirport();
    // check if source and destination exist in airports data
    if (airports.find(dest_port_id) != airports.end() &&
      airports.find(source_port_id) != airports.end()) {
      
      // if exists and source vertex does not exist, create and add vertex in graph
      if (!graph.vertexExists(source_port_id)) {
        graph.insertVertex(source_port_id);   
      } 
      // if exists and destination vertex does not exist, create and add vertex in graph
      if (!graph.vertexExists(dest_port_id)) {
        graph.insertVertex(dest_port_id);
      }
      // create edge connecting source and dest
      graph.insertEdge(source_port_id, dest_port_id);
      Airport source_port = airports.at(source_port_id);
      Airport dest_port = airports.at(dest_port_id);
      double dist = getDistanceFromLatLong(source_port.getLatitude(), source_port.getLongitude(),
                                          dest_port.getLatitude(), dest_port.getLongitude());
      // edge weight is the distance betweeen source and destination
      graph.setEdgeWeight(source_port_id, dest_port_id, dist);
      // set edge label
      graph.setEdgeLabel(source_port_id, dest_port_id, source_port.getName() + "\x1b[1m=>\x1b[0m" + dest_port.getName());
    }    
  }

  return graph;
}