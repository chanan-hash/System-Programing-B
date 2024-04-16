#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <string>
#include <climits>
#include <queue>

using namespace std;

/**
 * By given graph as adjacency matrix we want to check if it is a connected graph
 * The main idea is to run dfs, traves the graph and run it again from the first vertex
 * */

// Depth-first search algorithm
// void dfs(Graph g, int vertex, vector<bool> &visited)
// {
//     visited[vertex] = true;

//     // Traverse all adjacent vertices
//     for (int i = 0; i < g.getNumVertices(); i++)
//     {
//         if (g.isEdge(vertex, i) && !visited[i])
//         {
//             dfs(g, i, visited);
//         }
//     }
// }

// bool isConnected(Graph g)
// {
//     int numVertices = g.getNumVertices();
//     vector<bool> visited(numVertices, false);

//     // Perform depth-first search starting from vertex 0
//     dfs(g, 0, visited);

//     // Check if all vertices were visited
//     for (bool v : visited)
//     {
//         if (!v)
//         {
//             return false;
//         }
//     }

//     return true;
// }

/**
 * Using the bfs algorithm to check if the graph is connected.
 * Because the graph is undirected we can start from any vertex, and if it is connected we will reach all the vertices
*/

bool isConnected(Graph graph)
{
    // Assuming the graph is undirected
    int numVertices = graph.getNumVertices();
    vector<bool> visited(numVertices, false);
    queue<int> q;
    q.push(0); // start from the first vertex
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        vector<vector<int>> adjacencyMatrix = graph.getAdjMatrix();
        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }
    return true;
}


bool isContainsCycle(Graph g)
{
}

string shortestPath(Graph& g, int start, int end) {
    int numVertices = g.getNumVertices();
    vector<int> distance(numVertices, INT_MAX);
    vector<int> predecessor(numVertices, -1);
    distance[start] = 0;

    // Relax edges |V| - 1 times
    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = 0; j < numVertices; j++) {
            for (int k = 0; k < numVertices; k++) {
                if (g.isEdge(j, k) && distance[j] != INT_MAX && distance[j] + g.getEdgeWeight(j, k) < distance[k]) {
                    distance[k] = distance[j] + g.getEdgeWeight(j, k);
                    predecessor[k] = j;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < numVertices; j++) {
        for (int k = 0; k < numVertices; k++) {
            if (g.isEdge(j, k) && distance[j] != INT_MAX && distance[j] + g.getEdgeWeight(j, k) < distance[k]) {
                return "-1";
            }
        }
    }

    // If there is no path from start to end
    if (distance[end] == INT_MAX) {
        return "-1";
    }

    // Build the shortest path from end to start
    string path = to_string(end);
    for (int v = end; v != start; v = predecessor[v]) {
        path = to_string(predecessor[v]) + " -> " + path;
    }

    return path;
}
