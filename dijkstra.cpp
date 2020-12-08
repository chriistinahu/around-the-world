#include "dijkstra.h"
#include <queue>
#include "graph.h"

using namespace traversals;

typedef pair<double, Vertex> vPair;

map<Vertex, double> Dijkstra::dijkstra_main(Graph g, Vertex source) {
    map<Vertex, double> distances;
    map<Vertex, Vertex> previous;
    priority_queue<vPair, vector<vPair>, greater<vPair>> pq;
    // source_ = source;

    for (Vertex v: g.getVertices()) {
      // in beginning, assume distance from source vertex to all other verticies is INF
      distances.insert(pair<Vertex, double>(v, INT_MAX));
      // initialize all previous verticies to null at first
      previous.insert(pair<Vertex, Vertex>(v, Vertex()));
    }

    // distance from source to itself is 0
    pq.push(make_pair(0.0, source));
    distances[source] = 0.0;

    // loop while pq is not empty
    while(!pq.empty()){
        Vertex u = pq.top().second;  
        pq.pop();

        // get neighbors of current vertex
        vector<Vertex> neighbors = g.getAdjacent(u);
        // go through the neighbors
        for (Vertex v: neighbors) {
            // check if we have found a shorter path from source to v
            if (distances[u] + g.getEdgeWeight(u, v) < distances[v]) {
              // update distance from source to the unvisited neighbors
              distances[v] = distances[u] + g.getEdgeWeight(u, v);
              // keeps track of previous vertex from current vertex
              previous[v] = u;
              // add the newly calculated distances from current vector and current vector to pq
              pq.push(make_pair(distances[v], v));
            }
            
        }
    }

    // all_path_distances_ = distances;
    return distances;
}

vector<Vertex> Dijkstra::dijkstra_path(Graph g, Vertex source, Vertex dest) {
    map<Vertex, double> distances;
    map<Vertex, Vertex> previous;
    priority_queue<vPair, vector<vPair>, greater<vPair>> pq;

    for (Vertex v: g.getVertices()) {
      // in beginning, assume distance from source vertex to all other verticies is INF
      distances.insert(pair<Vertex, double>(v, INT_MAX));
      // initialize all previous verticies to null at first
      previous.insert(pair<Vertex, Vertex>(v, Vertex()));
    }

    // distance from source to itself is 0
    pq.push(make_pair(0.0, source));
    distances[source] = 0.0;

    Graph T(true, true);
        
    // loop while pq is not empty
    while(!pq.empty()){
        Vertex u = pq.top().second;  
        pq.pop();

        // get neighbors of current vertex
        vector<Vertex> neighbors = g.getAdjacent(u);
        // go through the neighbors
        for (Vertex v: neighbors) {
            // check if we have found a shorter path from source to v
            if (distances[u] + g.getEdgeWeight(u, v) < distances[v]) {
              // update distance from source to the unvisited neighbors
              distances[v] = distances[u] + g.getEdgeWeight(u, v);
              // keeps track of previous vertex from current vertex
              previous[v] = u;
              // add the newly calculated distances from current vector and current vector to pq
              pq.push(make_pair(distances[v], v));
            }
            
        }
    }

    // if dest doesn't have a previous Vertex, a path doesn't exist
    if (previous.count(dest) == 0) {
      return {};
    }
    
    Vertex current = dest;
    vector<Vertex> path;
    path.push_back(current);
    // as long as current vertex is not source vertex, keep adding to path (backwards)
    while (previous.at(current) != source) {
      std::cout << current << " " << previous.at(current) << std::endl;
      path.push_back(previous.at(current));
      current = previous.at(current);
    }
    // the while loop ends before reaching source vertex, so need to push back source at end
    path.push_back(source);
    // get the actual path by reversing!!
    std::reverse(path.begin(), path.end());
    return path;

}

// void Dijkstra::printToFile(string file_name) {
//   ofstream myfile;
//   myfile.open (file_name);
//   myfile << "From source airport" << ;
//   myfile.close();
// }