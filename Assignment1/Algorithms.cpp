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

// For running the DFS visit in the graph as we had in algo-1 course
#define WHITE 1
#define GRAY 2
#define BLACK 3

/*******************  This part for now will hadle direct graph we'll ************************/

/** for shortest path we'll check what kind of a graph it is:
 * 1. if it is an unweighted graph we'll use BFS
 * 2. if it is a non-negatiive weighted graph we'll use Dijkstra's algorithm
 * 3. if it is a negative weighted graph we'll use Bellman-Ford algorithm
 *
 * for now we'll handle the unweighted and undirect graph
 * if we have only 0 and 1, it is an unweighted graph --> return 1
 * if we have not only 0, 1, it is a weighted graph --> return 2
 * if we have less than it is a negative weighted graph --> return 3
 */
int whatGraph(Graph g)
{
    vector<vector<int>> matrix = g.getAdjMatrix();
    int n = matrix.size();
    int kind = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < 0)
            {
                return 3; // we knwo it is a negative weighted graph and can return
            }
            else if (matrix[i][j] > 1)
            {
                kind = 2; // and return only in the end
            }
        }
    }
    return kind;
}

/**
 * To check if graph is connected we can use the DFS algorithm.
 * The output of it will be the forset of the DFS's trees.
 * Then we'll take the last root in the forest and run the DFS again.
 * If we've visited all the vertices we can say that the graph is connected.
 * Each tree will be represented as a vector of the vertices, And the forest will be the matrix
 */

// vector<vector<int>> DFS_Forest(Graph g)
// {
//     size_t n = g.getNumVertices();
//     vector<bool> visited(n, false);
//     vector<vector<int>> forest;
//     vector<vector<int>> adjmatrix = g.getAdjMatrix();

//     for (int i = 0; i < n; i++) // ensure that we've visited all the vertices, even if the graph is not connected
//     {
//         if (!visited[i]) // if vertex is not visited
//         {
//             stack<int> s; // the stack of the dfs (usually dfs is recursive the stack is the calling stack, but can be also iterative)
//             vector<int> tree;
//             s.push(i); // the root of the tree
//             visited[i] = true;

//             while (!s.empty()) // The dfs visit
//             {
//                 int u = s.top();   // saving the current node
//                 s.pop();           // taking it out of the stack, pop is void
//                 tree.push_back(u); // adding the node to the tree

//                 for (int neighbor : adjmatrix[u]) // going all over the neighbors of the current node
//                 {
//                     if (neighbor != 0 && !visited[neighbor]) // if the neighbor is not visited and it's no 0, means there an edge between them
//                     {
//                         s.push(neighbor);         // push the neighbor to the stack for the dfs visit
//                         visited[neighbor] = true; // marked as visited
//                     }
//                 }
//             }
//             forest.push_back(tree); // putting the tree inside the forest
//         }
//     }

//     return forest;
// }

// // This function is for the second time we're running the DFS from the last root of the forest
// // we have here overloaded function
// // we need to check again if we can visit all the vertices from the last root
// vector<vector<int>> DFS_Forest_Second(Graph &g, int lastroot)
// {
//     size_t n = g.getNumVertices();
//     vector<bool> visited(n, false); // initialize all the vertices as not visited again
//     vector<vector<int>> forest(n);
//     vector<vector<int>> adjmatrix = g.getAdjMatrix();

//     stack<int> s;
//     s.push(lastroot); // strating form him and we'll see if the out put will be inly one tree or not
//     visited[lastroot] = true;

//     // The DFS visit same as before
//     while (!s.empty())
//     {
//         int v = s.top(); // current vertex
//         s.pop();

//         for (int neighbor : adjmatrix[v])
//         {
//             if (neighbor != 0 && !visited[neighbor])
//             {
//                 s.push(neighbor);
//                 visited[neighbor] = true;
//                 forest[v].push_back(neighbor);
//             }
//         }
//     }

//     return forest;
// }

bool Algorithms::isConnected(Graph g)
{
    // vector<vector<int>> forest = DFS_Forest(g);
    // int lastroot = forest.back().front(); // the last root of the forest
    // vector<vector<int>> secondforest = DFS_Forest_Second(g, lastroot);
    // int num_trees = secondforest.size(); // the number of trees in the forest
    // if (num_trees == 1)                  // means the graph is connected
    // {
    //     return true;
    // }
    return false;
}

string writingCycle(vector<int> &path, int start)
{
    string cycle;
    size_t Cstart = 0; // variable for the start of the cycle
    for (Cstart = 0; Cstart < path.size(); ++Cstart)
    {
        if (path[Cstart] == start) // find the start of the cycle
        {
            break;
        }
    }
    for (size_t j = Cstart; j < path.size(); ++j)
    {
        cycle += to_string(path[j]) + "->";
    }
    cycle += to_string(start); // to complete the cycle
    return cycle;
}

// The DFS visit in the graph for checking cycle if we've found a gray vertex we have a cycle
// we're passing pointers because we want to keep the change themselves
string DFScycleCheck(Graph &g, size_t current, vector<int> *colors, vector<int> *parents, vector<int> *path)
{
    size_t n = g.getNumVertices();
    // each vertex has a we're writing it's color in the colors vector
    (*colors)[current] = GRAY; // we are visitng this vertex now
    path->push_back(current);  // add the vertex to the path

    for (size_t v = 0; v < n; v++) // visit all the vertices
    {
        if (g.getAdjMatrix()[current][v] != 0)
        { // there is an edge
            if ((*colors)[v] == WHITE)
            { // mean we came from here to the vertex
                (*parents)[v] = (int)current;
                string cycle = DFScycleCheck(g, v, colors, parents, path); // visit by the DFS
                if (!cycle.empty())                                        // means we've got a cycle string
                {
                    return cycle;
                }
            }
            else if ((*colors)[v] == GRAY) // we've a gray reached a gray vertex from which we came
                                           // means there is a cycle
            {
                return writingCycle(*path, v);
            }
        }
    }
    (*colors)[current] = BLACK; // we've finished visiting this vertex
    path->pop_back();           // remove the vertex from the path because we are done with it
    return "";
}

// By runing the DFS
bool Algorithms::isContainsCycle(Graph g)
{
    size_t n = g.getNumVertices();
    vector<int> colors(n, WHITE); // like in DFS as we've learned in the course algo-1
    vector<int> parents(n, -1);
    vector<int> path;

    for (size_t i = 0; i < n; i++) // going through all the vertices
    {
        if (colors[i] == WHITE)
        {
            // if it we'll return nothing for all the vertices means there no cycle
            string cycle = DFScycleCheck(g, i, &colors, &parents, &path);
            if (!cycle.empty())
            {
                cout << cycle << endl; // print the cycle
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

string BFS(Graph &g, int start, int end)
{

    size_t V = g.getNumVertices();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == end)
        {
            // Reconstruct the path from end to start
            string path = to_string(end);
            while (parent[end] != -1)
            {
                path = to_string(parent[end]) + " -> " + path;
                end = parent[end];
            }
            return path;
        }

        for (int i = 0; i < V; ++i)
        {
            if (g.getAdjMatrix()[u][i] != 0 && !visited[i]) // if there's no edge and we havent visieted him
            {
                q.push(i);
                visited[i] = true; // mark as visited
                parent[i] = u;     // set the parent
            }
        }
    }
    return "No path found";
}

// Dijkstra algorithm for shortest path, on weighted graph
string dijksra(Graph &g, int start, int end)
{

    int n = g.getNumVertices();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    // The priority queue will contain pairs of (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // The distance from start to itself is 0
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        if (u == end)
        {
            // Reconstruct the path from end to start
            string path = to_string(end);
            while (parent[end] != -1)
            {
                path = to_string(parent[end]) + " -> " + path;
                end = parent[end];
            }
            return path;
        }

        for (int i = 0; i < n; ++i)
        {
            if (g.getAdjMatrix()[u][i] != 0 && !visited[i])
            {
                int newDist = dist[u] + g.getAdjMatrix()[u][i];
                if (newDist < dist[i])
                {
                    dist[i] = newDist;
                    parent[i] = u;
                    pq.push({dist[i], i});
                }
            }
        }
    }

    return "No path found";
}

string bellmanFord(Graph &g, int start, int end)
{
    size_t numVertices = g.getNumVertices();
    vector<int> distance(numVertices, INT_MAX);
    vector<int> predecessor(numVertices, -1);
    distance[(size_t)start] = 0;

    vector<vector<int>> adjacencyMatrix = g.getAdjMatrix();
    for (size_t i = 0; i < numVertices - 1; i++)
    {
        for (size_t j = 0; j < numVertices; j++)
        {
            for (size_t k = 0; k < numVertices; k++)
            {
                if (adjacencyMatrix[j][k] && distance[j] != INT_MAX && distance[j] + adjacencyMatrix[j][k] < distance[k])
                {
                    distance[k] = distance[j] + adjacencyMatrix[j][k];
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
            if (adjacencyMatrix[j][k] && distance[j] != INT_MAX && distance[j] + adjacencyMatrix[j][k] < distance[k])
            {
                return "Negative cycle detected";
            }
        }
    }

    // If there is no path from start to end
    if (distance[(size_t)end] == INT_MAX)
    {
        return "No path found";
    }

    // Build the shortest path from end to start
    string path = to_string(end);
    for (size_t v = (size_t)end; v != (size_t)start; v = (size_t)predecessor[v])
    {
        path = to_string(predecessor[v]) + " -> " + path;
    }

    return path;
}

// According to what is returning  form graph kind we'll use the correct algorithm
string Algorithms::shortestPath(Graph &g, int start, int end)
{
    if (start < 0 || start >= g.getNumVertices() || end < 0 || end >= g.getNumVertices())
    {
        return "No path found";
    }

    int kind = whatGraph(g);

    switch (kind)
    {
    case 1:
        return BFS(g, start, end);
        break;
    case 2:
        return dijksra(g, start, end);
        break;
    case 3:
        return bellmanFord(g, start, end);
        break;
    }

    return "No path found";
}

// To check negative cycle in a graph we just need to run bellman-ford algorithm and che what have returned
bool Algorithms::negativeCycle(Graph g)
{
    return shortestPath(g, 0, 0) == "Negative cycle detected";
    // return whatGraph(g) == 3; // in undirected graph, the minimum we've found a negative edge we can have a negative cycle.
    // Because we can go back and forth between the two vertices, and reduce the path weight
}

string Algorithms::isBipartite(Graph g)
{
    int n = g.getNumVertices();
    vector<int> color(n, -1);      // -1 means no color, 0 and 1 are the two colors
    vector<vector<int>> groups(2); // groups[0] and groups[1] are the two groups of vertices

    for (int start = 0; start < n; ++start)
    {
        if (color[start] == -1)
        {
            queue<int> q;
            q.push(start);
            color[start] = 0;
            groups[0].push_back(start);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int i = 0; i < n; ++i)
                {
                    if (g.getAdjMatrix()[node][i] != 0)
                    {
                        if (color[i] == -1)
                        {
                            // If the node has not been colored, color it with the opposite color and add it to the corresponding group
                            color[i] = 1 - color[node];
                            groups[color[i]].push_back(i);
                            q.push(i);
                        }
                        else if (color[i] == color[node])
                        {
                            // If the node has been colored and its color is the same as the current node, the graph is not bipartite
                            return "The graph is not bipartite";
                        }
                    }
                }
            }
        }
    }

    vector<int> groupA;
    vector<int> groupB;
    for (size_t i = 0; i < n; ++i)
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
    return "";
}
