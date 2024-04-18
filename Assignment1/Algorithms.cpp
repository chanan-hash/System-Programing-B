#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <string>
#include <climits>
#include <queue>

using namespace std;
using namespace ariel;

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

bool Algorithms::isConnected(Graph graph)
{
    // Assuming the graph is undirected
    size_t numVertices = graph.getNumVertices();
    vector<bool> visited(numVertices, false);
    queue<size_t> q;
    q.push(0); // start from the first vertex
    visited[0] = true;

    while (!q.empty())
    {
        size_t current = q.front();
        q.pop();

        vector<vector<int>> adjacencyMatrix = graph.getAdjMatrix();
        for (size_t i = 0; i < numVertices; ++i)
        {
            if (adjacencyMatrix[current][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    for (bool v : visited)
    {
        if (!v)
        {
            return false;
        }
    }
    return true;
}

// bool Algorithms:: isContainsCycle(Graph g)
// {
// }

/**
 * To check if a graph contains a cycle,
 * we'll depth-first search (DFS) with a slight modification.
 * The idea is to keep track of the vertices currently in the recursion stack of function for DFS traversal.
 * If a vertex is reached that is already in the recursion stack,
 * then there is a cycle in the tree.
 * 
 * We can usi the idea of finding which kind of edges we have in the graph
 * if we have back edge then we have a cycle
*/
bool isCyclicUtil(Graph g, int v, vector<bool> &visited, vector<bool> &recStack)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < g.getNumVertices(); ++i)
        {
            if (g.isEdge(v, i))
            {
                if (!visited[i] && isCyclicUtil(g, i, visited, recStack))
                {
                    return true;
                }
                else if (recStack[i])
                {
                    return true;
                }
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool Algorithms::isContainsCycle(Graph g)
{
    int numVertices = g.getNumVertices();
    vector<bool> visited(numVertices, false);
    vector<bool> recStack(numVertices, false);

    for (int i = 0; i < numVertices; i++)
    {
        if (isCyclicUtil(g, i, visited, recStack))
        {
            return true;
        }
    }

    return false;
}







/**
 * Using Bellman-Ford algorithm for shortest path,
 * beacuse we don't  know if the graph is weighted or not, or negative weights
 */
string Algorithms::shortestPath(Graph &g, int start, int end)
{
    size_t numVertices = g.getNumVertices();
    vector<size_t> distance(numVertices, INT_MAX);
    vector<size_t> predecessor(numVertices, (size_t)-1);
    distance[(size_t)start] = 0;

    // Relax edges |V| - 1 times
    for (size_t i = 0; i < numVertices - 1; i++)
    {
        for (size_t j = 0; j < numVertices; j++)
        {
            for (size_t k = 0; k < numVertices; k++)
            {
                if (g.isEdge(j, k) && distance[j] != INT_MAX && distance[j] + (size_t)g.getEdgeWeight(j, k) < distance[k])
                {
                    distance[k] = distance[j] + (size_t)g.getEdgeWeight(j, k);
                    predecessor[k] = j;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (size_t j = 0; j < numVertices; j++)
    {
        for (size_t k = 0; k < numVertices; k++)
        {
            if (g.isEdge(j, k) && distance[j] != INT_MAX && distance[j] + (size_t)g.getEdgeWeight(j, k) < distance[k])
            {
                return "-1";
            }
        }
    }

    // If there is no path from start to end
    if (distance[(size_t)end] == INT_MAX)
    {
        return "-1";
    }

    // Build the shortest path from end to start
    string path = to_string(end);
    for (size_t v = (size_t)end; v != (size_t)start; v = (size_t)predecessor[v])
    {
        path = to_string(predecessor[v]) + " -> " + path;
    }

    return path;
}