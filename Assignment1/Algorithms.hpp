// mail - chanahelamn@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include <vector>
#include "Graph.hpp" // Include the Graph file
#include <string>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdexcept>

namespace ariel
{
    class Algorithms
    {
    public:
        static bool isConnected(Graph &g); // returning true or false if the graph is connected (not SCC, regular connection)

        static string shortestPath(Graph &g, int start, int end); // returning the shorest path between to given vertices, using one of 3 algorithms

        static bool isContainsCycle(Graph &g); // returning true or false if the graph contains a cycle and printing it

        static string isBipartite(Graph &g); // Check if the graph is bipartite by trying to color it

        static string negativeCycle(Graph &g); // returning the negative cycle in the graph if there is one
    };
}

#endif // ALGORITHMS_HPP