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

/*******************  This part for now will hadle direct graph we'll ************************/
// The issue arises because the isCyclicUtil function checks for cycles that include the parent node. In a directed graph,
// we don't need to consider the parent node because the direction of the edges matters.
bool isCyclicUtil(int v, vector<bool> &visited, vector<int> &cycle, Graph &g)
{
    visited[v] = true;
    cycle.push_back(v);

    for (int i = 0; i < g.getNumVertices(); ++i)
    {
        if (g.getAdjMatrix()[v][i] != 0)
        {
            if (!visited[i])
            {
                if (isCyclicUtil(i, visited, cycle, g))
                {
                    return true;
                }
            }
            else
            {
                cycle.push_back(i);
                return true;
            }
        }
    }

    cycle.pop_back();
    return false;
}

bool Algorithms::isContainsCycle(Graph g)
{
    vector<bool> visited(g.getNumVertices(), false);
    vector<int> cycle;

    for (int i = 0; i < g.getNumVertices(); ++i)
    {
        if (!visited[i])
        {
            if (isCyclicUtil(i, visited, cycle, g))
            {
                for (int j = 0; j < cycle.size() - 1; ++j)
                {
                    cout << cycle[j] << "->";
                }
                cout << cycle.back() << endl; // Print the last vertex to complete the cycle
                return true;
            }
        }
    }

    return false;
}











/*******************  This part for now will hadle undirect graph we'll ************************/
/**
 * Using the bfs algorithm to check if the graph is connected.
 * Because the graph is undirected we can start from any vertex, and if it is connected we will reach all the vertices
 */

// bool Algorithms::isConnected(Graph graph)
// {
//     // Assuming the graph is undirected
//     size_t numVertices = graph.getNumVertices();
//     vector<bool> visited(numVertices, false);
//     queue<size_t> q;
//     q.push(0); // start from the first vertex
//     visited[0] = true;

//     while (!q.empty())
//     {
//         size_t current = q.front();
//         q.pop();

//         vector<vector<int>> adjacencyMatrix = graph.getAdjMatrix();
//         for (size_t i = 0; i < numVertices; ++i)
//         {
//             if (adjacencyMatrix[current][i] && !visited[i])
//             {
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
//     for (bool v : visited)
//     {
//         if (!v)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// /**
//  * To check if a graph contains a cycle,
//  * we'll depth-first search (DFS) with a slight modification.
//  * The idea is to keep track of the vertices currently in the recursion stack of function for DFS traversal.
//  * If a vertex is reached that is already in the recursion stack,
//  * then there is a cycle in the tree.
//  *
//  * We can usi the idea of finding which kind of edges we have in the graph
//  * if we have back edge then we have a cycle
//  */

// bool hasCycleDFS(Graph &g, int node, vector<bool> &visited, vector<int> &parent, stack<int> &path)
// {
//     visited[node] = true;
//     path.push(node);
//     int n = g.getNumVertices();
//     // Visit all adjacent nodes
//     for (int i = 0; i < n; ++i)
//     {
//         if (g.getAdjMatrix()[node][i] != 0)
//         {
//             // If the adjacent node is not visited, recursively visit it
//             if (!visited[i])
//             {
//                 parent[i] = node;
//                 if (hasCycleDFS(g, i, visited, parent, path))
//                     return true;
//             }
//             // If the adjacent node is already visited and not the parent of current node, cycle exists
//             else if (i != parent[node])
//             {
//                 // Print the cycle using the path
//                 cout << "The cycle is: ";

//                 stack<int> cycle;
//                 while (!path.empty())
//                 {
//                     int current = path.top();
//                     cycle.push(current);
//                     path.pop();
//                     if (current == i)
//                         break;
//                 }
//                 while (!cycle.empty())
//                 {
//                     cout << cycle.top();
//                     cycle.pop();
//                     if (!cycle.empty())
//                         cout << "->";
//                 }
//                 cout << "->" << i << endl;
//                 return true;
//             }
//         }
//     }

//     path.pop(); // Remove the current node from the path as we backtrack
//     return false;
// }

// // Function to check if the graph has a cycle
// bool Algorithms::isContainsCycle(Graph g)
// {
//     int n = g.getNumVertices();
//     vector<bool> visited(n, false);
//     vector<int> parent(n, -1); // Array to keep track of parent nodes in DFS
//     stack<int> path;

//     // Iterate through each node and perform DFS if not visited
//     for (int i = 0; i < n; ++i)
//     {
//         if (!visited[i])
//         {
//             if (hasCycleDFS(g, i, visited, parent, path)) // Parent is -1 for the starting node
//                 return true;
//         }
//     }

//     return false;
// }

// // TODO check the function for undirected graphs

// /** for shortest path we'll check what kind of a graph it is:
//  * 1. if it is an unweighted graph we'll use BFS
//  * 2. if it is a non-negatiive weighted graph we'll use Dijkstra's algorithm
//  * 3. if it is a negative weighted graph we'll use Bellman-Ford algorithm
//  *
//  * for now we'll handle the unweighted and undirect graph
//  * if we have only 0 and 1, it is an unweighted graph --> return 1
//  * if we have not only 0, 1, it is a weighted graph --> return 2
//  * if we have less than it is a negative weighted graph --> return 3
//  */
// int whatGraph(Graph g)
// {
//     vector<vector<int>> matrix = g.getAdjMatrix();
//     int n = matrix.size();
//     int kind = 1;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matrix[i][j] < 0)
//             {
//                 return 3; // we knwo it is a negative weighted graph and can return
//             }
//             else if (matrix[i][j] > 1)
//             {
//                 kind = 2; // and return only in the end
//             }
//         }
//     }
//     return kind;
// }

// string bfsUndirect(Graph &g, int start, int end)
// {

//     int V = g.getNumVertices();
//     if (start > V || end > V) // no vertice like this
//     {
//         return "No path found";
//     }

//     vector<bool> visited(V, false);
//     vector<int> parent(V, -1);
//     queue<int> q;

//     q.push(start);
//     visited[start] = true;

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         if (u == end)
//         {
//             // Reconstruct the path from end to start
//             string path = to_string(end);
//             while (parent[end] != -1)
//             {
//                 path = to_string(parent[end]) + " -> " + path;
//                 end = parent[end];
//             }
//             return path;
//         }

//         for (int i = 0; i < V; ++i)
//         {
//             if (g.getAdjMatrix()[u][i] != 0 && !visited[i])
//             {
//                 q.push(i);
//                 visited[i] = true;
//                 parent[i] = u;
//             }
//         }
//     }

//     return "No path found";
// }

// // Different algorithms for shortest path
// string dijksra(Graph &g, int start, int end)
// {
//     int n = g.getNumVertices();
//     vector<int> dist(n, INT_MAX);
//     vector<int> parent(n, -1);
//     vector<bool> visited(n, false);

//     // The priority queue will contain pairs of (distance, vertex)
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     // The distance from start to itself is 0
//     dist[start] = 0;
//     pq.push({0, start});

//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         pq.pop();

//         visited[u] = true;

//         if (u == end)
//         {
//             // Reconstruct the path from end to start
//             string path = to_string(end);
//             while (parent[end] != -1)
//             {
//                 path = to_string(parent[end]) + " -> " + path;
//                 end = parent[end];
//             }
//             return path;
//         }

//         for (int i = 0; i < n; ++i)
//         {
//             if (g.getAdjMatrix()[u][i] != 0 && !visited[i])
//             {
//                 int newDist = dist[u] + g.getAdjMatrix()[u][i];
//                 if (newDist < dist[i])
//                 {
//                     dist[i] = newDist;
//                     parent[i] = u;
//                     pq.push({dist[i], i});
//                 }
//             }
//         }
//     }

//     return "No path found";
// }

// string bellmanFord(Graph &g, int start, int end)
// {
//     size_t numVertices = g.getNumVertices();
//     vector<int> distance(numVertices, INT_MAX);
//     vector<int> predecessor(numVertices, -1);
//     distance[(size_t)start] = 0;

//     vector<vector<int>> adjacencyMatrix = g.getAdjMatrix();
//     for (size_t i = 0; i < numVertices - 1; i++)
//     {
//         for (size_t j = 0; j < numVertices; j++)
//         {
//             for (size_t k = 0; k < numVertices; k++)
//             {
//                 if (adjacencyMatrix[j][k] && distance[j] != INT_MAX && distance[j] + adjacencyMatrix[j][k] < distance[k])
//                 {
//                     distance[k] = distance[j] + adjacencyMatrix[j][k];
//                     predecessor[k] = j;
//                 }
//             }
//         }
//     }

//     // Check for negative-weight cycles
//     for (size_t j = 0; j < numVertices; j++)
//     {
//         for (size_t k = 0; k < numVertices; k++)
//         {
//             if (adjacencyMatrix[j][k] && distance[j] != INT_MAX && distance[j] + adjacencyMatrix[j][k] < distance[k])
//             {
//                 return "Negative cycle detected";
//             }
//         }
//     }

//     // If there is no path from start to end
//     if (distance[(size_t)end] == INT_MAX)
//     {
//         return "No path found";
//     }

//     // Build the shortest path from end to start
//     string path = to_string(end);
//     for (size_t v = (size_t)end; v != (size_t)start; v = (size_t)predecessor[v])
//     {
//         path = to_string(predecessor[v]) + " -> " + path;
//     }

//     return path;
// }

// // According to what is returning  form graph kind we'll use the correct algorithm
// string Algorithms::shortestPath(Graph &g, int start, int end)
// {
//     int kind = whatGraph(g);

//     switch (kind)
//     {
//     case 1:
//         return bfsUndirect(g, start, end);
//         break;
//     case 2:
//         return dijksra(g, start, end);
//         break;
//     case 3:
//         return bellmanFord(g, start, end);
//         break;
//     }

//     return "No path found";
// }

// // To check negative cycle in a graph we just need to run bellman-ford algorithm and che what have returned
// bool Algorithms::negativeCycle(Graph g)
// {
//     return shortestPath(g, 0, 0) == "Negative cycle detected";
//     // return whatGraph(g) == 3; // in undirected graph, the minimum we've found a negative edge we can have a negative cycle.
//     // Because we can go back and forth between the two vertices, and reduce the path weight
// }

// string Algorithms::isBipartite(Graph g)
// {
//     int n = g.getNumVertices();
//     vector<int> color(n, -1);      // -1 means no color, 0 and 1 are the two colors
//     vector<vector<int>> groups(2); // groups[0] and groups[1] are the two groups of vertices

//     for (int start = 0; start < n; ++start)
//     {
//         if (color[start] == -1)
//         {
//             queue<int> q;
//             q.push(start);
//             color[start] = 0;
//             groups[0].push_back(start);

//             while (!q.empty())
//             {
//                 int node = q.front();
//                 q.pop();

//                 for (int i = 0; i < n; ++i)
//                 {
//                     if (g.getAdjMatrix()[node][i] != 0)
//                     {
//                         if (color[i] == -1)
//                         {
//                             // If the node has not been colored, color it with the opposite color and add it to the corresponding group
//                             color[i] = 1 - color[node];
//                             groups[color[i]].push_back(i);
//                             q.push(i);
//                         }
//                         else if (color[i] == color[node])
//                         {
//                             // If the node has been colored and its color is the same as the current node, the graph is not bipartite
//                             return "The graph is not bipartite";
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     vector<int> groupA;
//     vector<int> groupB;
//     for (size_t i = 0; i < n; ++i)
//     {
//         if (color[i] == 0)
//         {
//             groupA.push_back(i);
//         }
//         else
//         {
//             groupB.push_back(i);
//         }
//     }

//     cout << "The graph is bipartite: A={";
//     for (size_t i = 0; i < groupA.size(); ++i)
//     {
//         cout << groupA[i];
//         if (i != groupA.size() - 1)
//         {
//             cout << ", ";
//         }
//     }
//     cout << "}, B={";
//     for (size_t i = 0; i < groupB.size(); ++i)
//     {
//         cout << groupB[i];
//         if (i != groupB.size() - 1)
//         {
//             cout << ", ";
//         }
//     }
//     cout << "}." << endl;
//     return "";
// }
