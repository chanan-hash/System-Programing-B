#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <string>
#include <climits>

using namespace std;

/**
 * By given graph as adjacency matrix we want to check if it is a connected graph
 * The main idea is to run dfs, traves the graph and run it again from the first vertex
 * */

// Depth-first search algorithm
void dfs(Graph g, int vertex, vector<bool> &visited)
{
    visited[vertex] = true;

    // Traverse all adjacent vertices
    for (int i = 0; i < g.getNumVertices(); i++)
    {
        if (g.isEdge(vertex, i) && !visited[i])
        {
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
    for (bool v : visited)
    {
        if (!v)
        {
            return false;
        }
    }

    return true;
}

// bool isContainsCycle(Graph g)
// {
// }

// beacuse we can have also negative weights we will use the bellman-ford algorithm
string shortestPath(Graph g, int start, int end)
{
    int numVertices = g.getNumVertices();
    vector<int> distance(numVertices, INT_MAX);
    vector<int> predecessor(numVertices, -1);
    distance[start] = 0;

    // Relax edges |V| - 1 times
    for (int i = 1; i <= numVertices - 1; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            for (int k = 0; k < numVertices; k++)
            {
                if (g.isEdge(j, k) && distance[j] != INT_MAX && distance[j] + g.getEdgeWeight(j, k) < distance[k])
                {
                    distance[k] = distance[j] + g.getEdgeWeight(j, k);
                    predecessor[k] = j;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < numVertices; j++)
    {
        for (int k = 0; k < numVertices; k++)
        {
            if (g.isEdge(j, k) && distance[j] != INT_MAX && distance[j] + g.getEdgeWeight(j, k) < distance[k])
            {
                return "-1";
            }
        }
    }

    // If there is no path from start to end
    if (distance[end] == INT_MAX)
    {
        return "-1";
    }

    // Build the shortest path from end to start
    string path = std::to_string(end);
    for (int v = end; v != start; v = predecessor[v])
    {
        path = std::to_string(predecessor[v]) + " -> " + path;
    }

    return path;
}
