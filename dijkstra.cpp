#include "dijkstra.h"

using namespace traversals;

void dijkstra_main(Graph g, Vertex source) {
    // in beginning, assume distance from source vertex to all other verticies is INF
    // TODO: initialize all distances to INF
    vector<double> distances_vec;
    // however, distance from source to itself is 0
    //TODO: set location of source vertex to 0


    // Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.
    // Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
    // Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance", then push the vertex with the new distance to the priority queue.
    // If the popped vertex is visited before, just continue without using it.
    // Apply the same algorithm again until the priority queue is empty.

}