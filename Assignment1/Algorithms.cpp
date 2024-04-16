#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace std;

/**
 * By given graph as adjacency matrix we want to check if it is a connected graph
 * The main idea is to run dfs, traves the graph and run it again from the first vertex
 * */  

// Depth-first search algorithm
void dfs(Graph g, int vertex, vector<bool>& visited)
{
    visited[vertex] = true;

    // Traverse all adjacent vertices
    for (int i = 0; i < g.getNumVertices(); i++) {
        if (g.isEdge(vertex, i) && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}


bool isConnected(Graph g)
{
    int numVertices = g.getNumVertices();
    vector<bool> visited(numVertices, false);

    // Perform depth-first search starting from vertex 0
    dfs(g, 0, visited);

    // Check if all vertices were visited
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}
