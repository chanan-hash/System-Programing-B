// mail - chanahelman@gmail.com

#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <string>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdexcept>

using namespace std;
using namespace ariel;

// For running the DFS visit in the graph as we had in algo-1 course
// We'll use the colors to mark the vertices
const int WHITE = 1;
const int GRAY = 2;
const int BLACK = 3;

/********Checking a regular connection in direct graph ********/

/**
 * To check if graph is connected we can use the DFS algorithm.
 * The output of it will be the forset of the DFS's trees.
 * Then we'll take the last root in the forest and run the DFS again.
 * If we've visited all the vertices we can say that the graph is connected.
 * Each tree will be represented as a vector of the vertices, And the forest will be the matrix
 */

// Return the tree of the DFS visit from one vertex
// We send the verticesColors by reference because we want to keep the changes
vector<size_t> DFS_Visit(Graph &g, size_t vertex, vector<int> &verticesColors)
{
    size_t V = g.getNumVertices();
    vector<size_t> tree; // Inintialzing the tree
    stack<size_t> s;     // The stack of the DFS visit, here we're doing it iteratively
    s.push(vertex);

    while (!s.empty())
    {
        size_t u = s.top(); // saving the vertex
        s.pop();            // poping it outs

        if (verticesColors[u] == WHITE) // means we've discovered the vertex
        {
            verticesColors[u] = GRAY; // marking as checking it now
            tree.push_back(u);        // because we've just discovered it we'll push it to the tree, and we can get here from his parent

            for (size_t v = 0; v < V; v++) // going over it's neighbors
            {
                if (g.getAdjMatrix()[u][v] != 0 && verticesColors[v] == WHITE) // if there is an edge and we haven't visited it (it is still WHITE)
                {
                    s.push(v); // adding all the white vertices from u to the DFS's stack
                }
            }
        }
        else if (verticesColors[u] == GRAY) // means we've visited the vertex
        {
            verticesColors[u] = BLACK; // marking as finished visiting
        }
    }
    return tree;
}

vector<vector<size_t>> DFS_Forest(Graph &g)
{
    size_t V = g.getNumVertices();
    vector<int> verticesColors(V, WHITE); // Like we've seen in the course algo-1
    vector<vector<size_t>> forest;        // The DFS forest output

    // going all over the vertices
    for (size_t i = 0; i < V; i++)
    {
        if (verticesColors[i] == WHITE) // if we are discovering this vertex now
        {
            vector<size_t> tree = DFS_Visit(g, i, verticesColors); // start the DFS visit from the vertex
            forest.push_back(tree);                                // pushing the visit tree in the forest
        }
    }
    return forest;
}

bool directedIsConnected(Graph &g)
{
    size_t n = g.getNumVertices();
    vector<vector<size_t>> forest = DFS_Forest(g); // getting the DFS's forest visit

    if (forest.size() == 1) // means we've visited all the vertices and it is connected
    {
        return true;
    }

    // If we have a forest from the DFS, we'll check from the last root if we can visit all the vertices
    // Because if we can it means we have one tree, we and the last root is the root of the tree with whole vertices
    // means there is a root that can get to all vertices
    size_t lastroot = forest.back().front(); // the last root of the forest

    vector<int> colors(g.getNumVertices(), WHITE); // initilzing the colors for the last DFS visit

    vector<size_t> dfs_last_v = DFS_Visit(g, lastroot, colors); // getting the DFS tree visit, from the last root
    size_t last_tree_size = dfs_last_v.size();                  // the number of vertices in the forest

    return last_tree_size == n; // if it is equal to the number of vertices, we've visited all the vertices
}

/********Checking a regular connection in undirect graph ********/

/**
 * Using the bfs algorithm to check if the graph is connected.
 * Because the graph is undirected we can start from any vertex, and if it is connected we will reach all the vertices
 */

bool undirectedIsConnected(Graph &graph)
{
    // Assuming the graph is undirected
    size_t numVertices = graph.getNumVertices();
    vector<bool> visited(numVertices, false);
    queue<size_t> q;   // The BFS queue
    q.push(0);         // start from the first vertex
    visited[0] = true; // marked as visited

    while (!q.empty())
    {
        size_t current = q.front(); // getting the vertex
        q.pop();                    // poping it out

        vector<vector<int>> adjacencyMatrix = graph.getAdjMatrix();
        for (size_t i = 0; i < numVertices; ++i)
        {
            if (adjacencyMatrix[current][i] != 0 && !visited[i]) // if there is an edge and we haven't visited this vertex
            {
                q.push(i);         // pushing it in the queue
                visited[i] = true; // marking as visited
            }
        }
    }
    for (bool v : visited) // checking if we've visited all the vertices or not
    {
        if (!v)
        {
            return false; // means there is a vertex that we haven't visited
        }
    }
    return true;
}

/***************** Cycle check in directed graph **************************/
// Sending the path by reference because we want to get the and keep the chc
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
    for (size_t j = Cstart; j < path.size(); ++j) // reconstruction the cycle
    {
        cycle += to_string(path[j]) + "->";
    }
    cycle += to_string(start); // to complete the cycle
    return cycle;
}

// The DFS visit in the graph for checking cycle if we've found a gray vertex  again (back edge) we have a cycle
// we're passing by reference because we want to keep the changes
string DFScycleCheck(Graph &g, size_t current, vector<int> &colors, vector<int> &parents, vector<int> &path)
{
    size_t n = g.getNumVertices();
    // each vertex has a we're writing it's color in the colors vector
    colors[current] = GRAY;  // we are visitng this vertex now
    path.push_back(current); // add the vertex to the path

    for (size_t v = 0; v < n; v++) // visit all the vertices
    {
        if (g.getAdjMatrix()[current][v] != 0) // there is an edge
        {
            if (colors[v] == WHITE) // mean we haven't visited it and we came from here to the vertex
            {
                parents[v] = (int)current;                                 // updating the parent
                string cycle = DFScycleCheck(g, v, colors, parents, path); // visit by the DFS, and see if we can reconstruct a cycle
                if (!cycle.empty())                                        // means we've got a cycle string
                {
                    return cycle;
                }
            }
            else if (colors[v] == GRAY) // we've a gray reached a gray vertex from which we came - back edge
                                        // means there is a cycle
            {
                return writingCycle(path, v);
            }
        }
    }
    colors[current] = BLACK; // we've finished visiting this vertex
    path.pop_back();         // remove the vertex from the path because we are done with it
    return "";               // empty string means we haven't found a cycle
}

// By runing the DFS
bool directedIsContainsCycle(Graph &g)
{
    size_t n = g.getNumVertices();
    vector<int> colors(n, WHITE); // like in DFS as we've learned in the course algo-1
    vector<int> parents(n, -1);   // helping us to check if we've reached a predecesseor vertex
    vector<int> path;             // the path to the actual cycle

    for (size_t i = 0; i < n; i++) // going through all the vertices
    {
        if (colors[i] == WHITE)
        {
            // if it we'll return nothing for all the vertices means there no cycle
            string cycle = DFScycleCheck(g, i, colors, parents, path);
            if (!cycle.empty())
            {
                cout << cycle << endl; // print the cycle
                return true;
            }
        }
    }
    return false;
}

/***************** Cycle check in undirected graph **************************/
/**
 * To check if a graph contains a cycle,
 * we'll depth-first search (DFS) with a slight modification.
 * The idea is to keep track of the vertices currently in the recursion stack of function for DFS traversal.
 * If a vertex is reached that is already in the recursion stack,
 * then there is a cycle in the tree.
 *
 * We can use the idea of finding which kind of edges we have in the graph
 * if we have back edge then we have a cycle
 */

bool hasCycleDFS(Graph &g, int node, vector<bool> &visited, vector<int> &parent, stack<int> &path)
{
    visited[(size_t)node] = true; // instead of colors
    path.push(node);
    size_t n = g.getNumVertices();

    // Visit all adjacent nodes
    for (size_t i = 0; i < n; ++i)
    {
        if (g.getAdjMatrix()[(size_t)node][i] != 0)
        {
            // If the adjacent node is not visited, recursively visit it
            if (!visited[i])
            {
                parent[i] = (size_t)node; // Update the parent node
                if (hasCycleDFS(g, i, visited, parent, path))
                {
                    return true;
                }
            }

            // If the adjacent node is already visited and not the parent of current node, cycle exists
            else if (i != parent[(size_t)node])
            {
                // Print the cycle using the path
                cout << "The cycle is: ";

                stack<int> cycle; // for reconstructing
                while (!path.empty())
                {
                    int current = path.top(); // saving the vertex
                    cycle.push(current);      // pushin to the cycle
                    path.pop();
                    if (current == i) // means we've got to the strat again
                    {
                        break;
                    }
                }

                while (!cycle.empty()) // printing the cycle
                {
                    cout << cycle.top();
                    cycle.pop();
                    if (!cycle.empty())
                    {
                        cout << "->";
                    }
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
bool undirectedIsContainsCycle(Graph &g)
{
    size_t n = g.getNumVertices();
    vector<bool> visited((size_t)n, false);
    vector<int> parent((size_t)n, -1); // Array to keep track of parent nodes in DFS
    stack<int> path;

    // Iterate through each node and perform DFS if not visited
    for (size_t i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            if (hasCycleDFS(g, i, visited, parent, path))
            { // Parent is -1 for the starting node
                return true;
            }
        }
    }

    return false;
}

/****************** Shortest Pathes ****************/
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
int whatGraph(Graph &g)
{
    vector<vector<int>> matrix = g.getAdjMatrix();
    int n = matrix.size();
    int kind = 1;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (matrix[i][j] < 0)
            {
                return 3; // we knwo it is a negative weighted graph and can return
            }
            if (matrix[i][j] > 1)
            {
                kind = 2; // and return only in the end
            }
        }
    }
    return kind;
}

string BFS(Graph &g, int start, int end)
{

    size_t V = g.getNumVertices();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;

    q.push(start);
    visited[(size_t)start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == end)
        {
            // Reconstruct the path from end to start, fron the parent vector
            string path = to_string(end);
            while (parent[(size_t)end] != -1)
            {
                // path = to_string(parent[(size_t)end]) + " -> " + path;
                path.insert(0, to_string(parent[(size_t)end]) + " -> ");
                end = parent[(size_t)end];
            }
            return path;
        }

        for (size_t i = 0; i < V; ++i)
        {
            if (g.getAdjMatrix()[(size_t)u][i] != 0 && !visited[i]) // if there's no edge and we havent visieted him
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

    size_t n = g.getNumVertices();
    vector<int> dist(n, INT_MAX);   // Distance from start to each vertex, initiliazed to infinity
    vector<int> parent(n, -1);      // Parent of each vertex in the shortest path
    vector<bool> visited(n, false); // Visited vertices

    // The priority queue will contain pairs of (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // The distance from start to itself is 0
    dist[(size_t)start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[(size_t)u] = true; // Updating to visited

        if (u == end) // If we've reached the end we want to reconstruct the path
        {
            // Reconstruct the path from end to start
            string path = to_string(end);
            while (parent[(size_t)end] != -1) // Going over the parent vector
            {
                // path = to_string(parent[(size_t)end]) + " -> " + path;
                path.insert(0, to_string(parent[(size_t)end]) + " -> ");
                end = parent[(size_t)end];
            }
            return path;
        }

        // finding all the vertices we can get from u
        for (size_t i = 0; i < n; ++i)
        {
            // Relax
            if (g.getAdjMatrix()[(size_t)u][i] != 0 && !visited[i])
            {
                int newDist = dist[(size_t)u] + g.getAdjMatrix()[(size_t)u][i];
                if (newDist < dist[i])
                {
                    dist[i] = newDist;
                    parent[i] = (size_t)u;
                    pq.push({dist[i], i});
                }
            }
        }
    }
    // Mean we haven't find a path
    return "No path found";
}

string bellmanFord(Graph &g, int start, int end)
{
    size_t numVertices = g.getNumVertices();
    vector<int> distance(numVertices, INT_MAX);
    vector<int> predecessor(numVertices, -1);
    distance[(size_t)start] = 0;

    vector<vector<int>> adjacencyMatrix = g.getAdjMatrix();
    // Running |n-1| iterations
    for (size_t i = 0; i < numVertices - 1; i++)
    {
        for (size_t j = 0; j < numVertices; j++)
        {
            for (size_t k = 0; k < numVertices; k++)
            {
                // Relax
                if (adjacencyMatrix[j][k] != 0 && distance[j] != INT_MAX && distance[j] + adjacencyMatrix[j][k] < distance[k])
                {
                    distance[k] = distance[j] + adjacencyMatrix[j][k];
                    predecessor[k] = j;
                }
            }
        }
    }

    // Check for negative-weight cycles, by doing anthoer iteration and finding if we can still relax the path
    for (size_t j = 0; j < numVertices; j++)
    {
        for (size_t k = 0; k < numVertices; k++)
        {
            if (adjacencyMatrix[j][k] != 0 && distance[j] != INT_MAX && distance[j] + adjacencyMatrix[j][k] < distance[k])
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
    for (size_t v = (size_t)end; v != start; v = (size_t)predecessor[v])
    {
        // path = to_string((int)predecessor[v]) + " -> " + path;
        path.insert(0, to_string((int)predecessor[v]) + " -> ");
    }

    return path;
}

/************* returning the negative cycle itself *************/
vector<int> negativeCyclePath(Graph g) // After we know we have a negative cycle, we'll find the cycle and print it
{
    size_t n = g.getNumVertices();
    vector<int> distance(n, INT_MAX);
    vector<int> predecessor(n, -1);
    int cycle_start = -1; // Will be the vertex where the cycle starts, if exists

    // Assume the source vertex is 0, for checking the negative cycle we'll run bellman-ford from the first vertex
    distance[0] = 0;

    // Runing n iterations to check if there is a negative cycle
    for (size_t i = 0; i < n; ++i)
    {
        cycle_start = -1; // Initilzing it in each iteration, in the last iteration if there is still relax, it will update the start of the cycle further
        for (size_t u = 0; u < n; ++u)
        {
            for (size_t v = 0; v < n; ++v)
            {
                if (g.getAdjMatrix()[u][v] != 0)
                {
                    // Relax the edge
                    int new_distance = distance[u] + g.getAdjMatrix()[u][v];
                    if (new_distance < distance[v])
                    {
                        distance[v] = new_distance;
                        predecessor[v] = (int)u;
                        cycle_start = v; // because if in the last iteration (n itreration) there is still relax,
                                         // means there is a negative cycle and we want to save the start.
                    }
                }
            }
        }
    }

    vector<int> cycle;     // To reconstruct the cycle if there is one
    if (cycle_start != -1) // means we found a strat of the cycke and it have kept the vertex that is starting from
    {
        // We found a negative cycle
        // Go n steps back to make sure we are in the cycle
        int v = cycle_start;
        for (size_t i = 0; i < n; ++i)
        {
            v = predecessor[(size_t)v];
        }

        // Add vertices to the cycle
        for (int u = v;; u = predecessor[(size_t)u])
        {
            cycle.push_back(u);
            if (u == v && cycle.size() > 1) // means we've got to the strat of the cycle, and it's bigger than 1, that t is not only one vertex
            {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end()); // beacuse we went backwards, we need to revers the cycle to get it
    }

    return cycle;
}

/******************** The hpp functions ********************/

bool Algorithms::isConnected(Graph &g)
{
    if (g.getNumVertices() == 0)
    {
        return true;
    }

    if (g.getDirected()) // if the graph is directed
    {
        return directedIsConnected(g);
    }
    return undirectedIsConnected(g);
}

bool Algorithms::isContainsCycle(Graph &g)
{
    if (g.getNumVertices() == 0)
    {
        return false;
    }

    if (g.getDirected()) // if the graph is directed
    {
        return directedIsContainsCycle(g);
    }
    return undirectedIsContainsCycle(g);
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
string Algorithms::negativeCycle(Graph &g)
{
    string result;
    if (shortestPath(g, 0, 0) == "Negative cycle detected") // for doing relaxation on all edges
    {
        vector<int> cycle = negativeCyclePath(g); // getting the actual cycle
        result = "Negative cycle detected: ";
        for (size_t i = 0; i < cycle.size(); ++i)
        {
            result += to_string(cycle[i]);
            if (i != cycle.size() - 1) // Not the last vertex
            {
                result += "->";
            }
        }
    }
    else
    {
        result = "No negative cycle detected";
    }
    return result;
}

/**
 *  To check if the graph is bipartite we'll use the BFS algorithm,
 *  and try to color the vertices with two colors.
 *  If the graph is directed we'll make it undirected, because we want to know only if there is an edge between the vertices
 */
string Algorithms::isBipartite(Graph &g) 
{

    /** if the graph is directed, we'll make it undirected, because we want to know only if there is an edge between the vertices
     * So if we have edje at [i][j] and [j][i] but with different weights, we'll consider it as a single edge
     * else we'll copy the value at [i][j] to [j][i], or opposite if needed
     */
    size_t n = g.getNumVertices();
    vector<vector<int>> adjMatrix = g.getAdjMatrix(); // getting the matrix to work on it

    if (g.getDirected())
    {
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (adjMatrix[i][j] != 0 && adjMatrix[j][i] == 0) // if there is an edge from i to j and not from j to i
                {
                    adjMatrix[j][i] = adjMatrix[i][j]; // copy the value from i to j
                }
                else if (adjMatrix[i][j] == 0 && adjMatrix[j][i] != 0) // if there is an edge from j to i and not from i to j
                {
                    adjMatrix[i][j] = adjMatrix[j][i]; // copy the value from j to i
                }
            }
        }
    }

    // trying to color the vertices with two colors, that no vertex and it's neighbor have the same color
    vector<int> color(n, -1);      // -1 means no color, 0 and 1 are the two colors
    vector<vector<int>> groups(2); // groups[0] and groups[1] are the two groups of vertices

    for (size_t start = 0; start < n; ++start)
    {
        if (color[start] == -1)
        {
            queue<int> q; // for the BFS check
            q.push(start);
            color[start] = 0; // coloring the start vertex with the first color
            groups[0].push_back(start);

            while (!q.empty())
            {
                int node = q.front(); // getting the vertex
                q.pop(); // poping it out

                for (size_t i = 0; i < n; ++i) // checking all the neighbors
                {
                    if (adjMatrix[(size_t)node][i] != 0) // if there is an edge
                    {
                        if (color[i] == -1) // checking if the vertex has't been colored
                        {
                            // If the node has not been colored, color it with the opposite color and add it to the corresponding group
                            color[i] = 1 - color[(size_t)node];
                            groups[(size_t)color[i]].push_back(i); // pushing the vertex to the group of its color
                            q.push(i);
                        }
                        else if (color[i] == color[(size_t)node]) // if the vertex and its neighbor have the same color
                        {
                            // If the node has been colored and its color is the same as the current node, the graph is not bipartite
                            return "The graph is not bipartite";
                        }
                    }
                }
            }
        }
    }

    // If we've reached here, the graph is bipartite and will return the two groups
    string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < groups[0].size(); ++i)
    {
        result += to_string(groups[0][i]);
        if (i != groups[0].size() - 1)
        {
            result += ", ";
        }
    }
    result += "}, B={";
    for (size_t i = 0; i < groups[1].size(); ++i)
    {
        result += to_string(groups[1][i]);
        if (i != groups[1].size() - 1)
        {
            result += ", ";
        }
    }
    result += "}.";
    return result;
}