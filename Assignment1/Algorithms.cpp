#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <string>
#include <climits>
#include <queue>
#include <stack>

using namespace std;
using namespace ariel;

/**
 * By given graph as adjacency matrix we want to check if it is a connected graph
 * The main idea is to run dfs, traves the graph and run it again from the first vertex
 * */

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
bool hasCycleDFS(Graph &g, int node, vector<bool> &visited, vector<int> &parent, stack<int> &path)
{
    visited[node] = true;
    path.push(node);
    int n = g.getNumVertices();
    // Visit all adjacent nodes
    for (int i = 0; i < n; ++i)
    {
        if (g.getAdjMatrix()[node][i] != 0)
        {
            // If the adjacent node is not visited, recursively visit it
            if (!visited[i])
            {
                parent[i] = node;
                if (hasCycleDFS(g, i, visited, parent, path))
                    return true;
            }
            // If the adjacent node is already visited and not the parent of current node, cycle exists
            else if (i != parent[node])
            {
                // Print the cycle using the path
                cout << "The cycle is: ";

                stack<int> cycle;
                while (!path.empty())
                {
                    int current = path.top();
                    cycle.push(current);
                    path.pop();
                    if (current == i)
                        break;
                }
                while (!cycle.empty())
                {
                    cout << cycle.top();
                    cycle.pop();
                    if (!cycle.empty())
                        cout << "->";
                }
                cout << "->" << i << endl;
                return true;
            }
        }
    }

    path.pop(); // Remove the current node from the path as we backtrack
    return false;
}

// Function to check if the graph has a cycle
bool Algorithms::isContainsCycle(Graph g)
{
    int n = g.getNumVertices();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1); // Array to keep track of parent nodes in DFS
    stack<int> path;

    // Iterate through each node and perform DFS if not visited
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            if (hasCycleDFS(g, i, visited, parent, path)) // Parent is -1 for the starting node
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

// TODO Check it
bool Algorithms::isBipartite(Graph g)
{
    size_t numVertices = g.getNumVertices();
    vector<int> color(numVertices, -1);
    queue<int> q;
    q.push(0); // start from the first vertex
    color[0] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        vector<vector<int>> adjacencyMatrix = g.getAdjMatrix();
        for (size_t i = 0; i < numVertices; ++i)
        {
            if (adjacencyMatrix[current][i] && color[i] == -1)
            {
                color[i] = 1 - color[current];
                q.push(i);
            }
            else if (adjacencyMatrix[current][i] && color[i] == color[current])
            {
                return false;
            }
        }
    }

    vector<int> groupA;
    vector<int> groupB;
    for (size_t i = 0; i < numVertices; ++i)
    {
        if (color[i] == 0)
        {
            groupA.push_back(i);
        }
        else
        {
            groupB.push_back(i);
        }
    }

    cout << "The graph is bipartite: A={";
    for (size_t i = 0; i < groupA.size(); ++i)
    {
        cout << groupA[i];
        if (i != groupA.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "}, B={";
    for (size_t i = 0; i < groupB.size(); ++i)
    {
        cout << groupB[i];
        if (i != groupB.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "}." << endl;

    return true;
}

/**
 * Using Bellman-Ford algorithm to check if the graph contains a negative cycle
 */

// bool Algorithms::negativeCycle(Graph g)
// {
// }
