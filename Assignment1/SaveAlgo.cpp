
/**
 * Using the bfs algorithm to check if the graph is connected.
 * Because the graph is undirected we can start from any vertex, and if it is connected we will reach all the vertices
 */

void dfs1(Graph g, int x, vector<bool> &vis1)
{
    vis1[x] = true;

    for (int i = 0; i < g.getNumVertices(); ++i)
    {
        if (g.isEdge(x, i) && !vis1[i])
        {
            dfs1(g, i, vis1);
        }
    }
}

void dfs2(Graph g, int x, vector<bool> &vis2)
{
    vis2[x] = true;

    for (int i = 0; i < g.getNumVertices(); ++i)
    {
        if (g.isEdge(i, x) && !vis2[i])
        {
            dfs2(g, i, vis2);
        }
    }
}

bool Algorithms::isConnected(Graph g)
{
    int numVertices = g.getNumVertices();
    vector<bool> vis1(numVertices, false);
    vector<bool> vis2(numVertices, false);

    // Call for correct direction
    dfs1(g, 0, vis1);

    // Call for reverse direction
    dfs2(g, 0, vis2);

    for (int i = 0; i < numVertices; i++)
    {
        // If any vertex it not visited in any direction
        // Then graph is not connected
        if (!vis1[i] && !vis2[i])
        {
            return false;
        }
    }

    // If graph is connected
    return true;
}

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
// TODO hanlde incorrect input
string Algorithms::shortestPath(Graph &g, int start, int end)
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
string Algorithms::isBipartite(Graph g)
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
                // return false;
                return "0";
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
    return "";
    // return true;
}

/**
 * Using Bellman-Ford algorithm to check if the graph contains a negative cycle
 * we need to do the bellman-fird because sometimes we just want to know if the graph contains a negative cycle, with finding  shortest path
 */
// TODO check it AND add a  bool variable
bool Algorithms::negativeCycle(Graph g)
{
    // bool isNegativeCycle = false;
    // if (shortestPath(g, 0, 0) == "Negative cycle detected") // instead doing the whole bellman-ford algorithm again, we can just check if the shortest path from a vertex to itself is -1
    // {
    //     isNegativeCycle = true;
    //     return isNegativeCycle;
    // }

    // if (shortestPath(g, 0, 0).compare("Negative cycle detected") == 0)
    // {
    //     return true;
    // }
    // return false;

    // return isNegativeCycle;
    return shortestPath(g, 0, 0) == "Negative cycle detected";
}
