#include "bfs.h"

using namespace traversals;

void BFS::BFS_main(Graph g) {

    for (Vertex v : g.getVertices()) {
        // initially, all vertices are set as UNEXPLORED
        explored_vertices.insert(std::pair<Vertex, bool>(v, false));
    }
    
    for (Edge e: g.getEdges()) {
        // initially, all edges are set as UNEXPLORED
        g.setEdgeLabel(e.source, e.dest, "UNEXPLORED");
    }

    for (Vertex v: g.getVertices()) {
        // if vertex is UNEXPLORED, do BFS
        if(!explored_vertices[v]) {
            BFS_whole(g, v);
        }
    }
}

void BFS::BFS_whole(Graph g, Vertex v) {
    queue<Vertex> q;
    // set current vertex status as VISITED
    explored_vertices.at(v) = true;
    q.push(v);

    while (!q.empty()) {
      Vertex current_vertex = q.front();
      q.pop();
      // loop through all neighboring vertices
      for (Vertex neighbor: g.getAdjacent(current_vertex)) {
        // if current vertex is UNEXPLORED
        if (!explored_vertices.at(neighbor)) {
          // set current edge label status as DISCOVERY
          g.setEdgeLabel(current_vertex, neighbor, "DISCOVERY");
          // keep track that we visited this neighbor
          explored_vertices.at(neighbor) = true;
          q.push(neighbor);
        // if neighbor vertex has been VISITED already and edge is UNEXPLORED, set to CROSS edge
        } else if (g.getEdgeLabel(current_vertex, neighbor) == "UNEXPLORED") {
          // make sure we don't set edge as CROSS multiple times??
          g.setEdgeLabel(current_vertex, neighbor, "CROSS");
        }
      }
    }
}

vector<Vertex> BFS::BFS_get_path(Graph g, Vertex source, Vertex dest) {
    for (Vertex v : g.getVertices()) {
        // initially, all vertices are set as UNEXPLORED
        explored_vertices.insert(std::pair<Vertex, bool>(v, false));
    }
    
    for (Edge e: g.getEdges()) {
        // initially, all edges are set as UNEXPLORED
        g.setEdgeLabel(e.source, e.dest, "UNEXPLORED");
    }
    queue<Vertex> q;
    // used to keep track of path 
    map<Vertex, Vertex> pred;
    // set current vertex status as VISITED
    explored_vertices.at(source) = true;
    q.push(source);

    while (!q.empty()) {
      Vertex current_vertex = q.front();
      q.pop();
      // loop through all neighboring vertices
      for (Vertex neighbor: g.getAdjacent(current_vertex)) {
        // if current vertex is UNEXPLORED
        if (!explored_vertices.at(neighbor)) {
          // insert the adj vertex to the vertex it came from
          pred.insert(std::pair<Vertex, Vertex>(neighbor, current_vertex));
          // if reach destination vertex, EXIT FOR LOOP
          if (neighbor == dest) {
            break;
          }
          // set current edge label status as DISCOVERY
          g.setEdgeLabel(current_vertex, neighbor, "DISCOVERY");
          // keep track that we visited this neighbor
          explored_vertices.at(neighbor) = true;
          q.push(neighbor);
        // if neighbor vertex has been VISITED already and edge is UNEXPLORED, set to CROSS edge
        } else if (g.getEdgeLabel(current_vertex, neighbor) == "UNEXPLORED") {
          // make sure we don't set edge as CROSS multiple times??
          g.setEdgeLabel(current_vertex, neighbor, "CROSS");
        }
      }
    }

    // dest doesn't have a previous Vertex, a path doesn't exist
    if (pred.count(dest) == 0) {
      return {};
    }
    
    // BACKTRACKING SECTION to find path
    Vertex current = dest;
    vector<Vertex> path;
    path.push_back(current);
    // as long as current vertex is not source vertex, keep adding to path (backwards)
    while (pred.at(current) != source) {
      path.push_back(pred.at(current));
      current = pred.at(current);
    }
    // the while loop ends before reaching source vertex, so need to push back source at end
    path.push_back(source);
    // get the actual path by reversing!!
    std::reverse(path.begin(), path.end());
    return path;
}