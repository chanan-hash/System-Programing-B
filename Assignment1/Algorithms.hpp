#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp" // Include the Graph file

bool isConnected(Graph g);
    // Your implementation to check if the graph is connected goes here
    // You can use any graph traversal algorithm, such as BFS or DFS, to check connectivity
    
    // Return true if the graph is connected, false otherwise

int shortestPath(Graph g,int start, int end);
    // Your implementation to find the shortest path in the graph goes here
    // You can use any graph traversal algorithm, such as BFS or DFS, to find the shortest path
    
    // Return the shortest path between the start and end vertices
    // If there is no path, return -1

bool isContainsCycle(Graph g);
    // Your implementation to check if the graph contains a cycle goes here
    // You can use any graph traversal algorithm, such as BFS or DFS, to check for cycles
    
    // Return true if the graph contains a cycle, false otherwise

bool isBiPartite(Graph g);
    // Your implementation to check if the graph is bipartite goes here
    // You can use any graph traversal algorithm, such as BFS or DFS, to check bipartiteness
    
    // Return true if the graph is bipartite, false otherwise

bool negativeCycle(Graph g);
    // Your implementation to check if the graph contains a negative cycle goes here
    // You can use any graph traversal algorithm, such as Bellman-Ford, to check for negative cycles
    
    // Return true if the graph contains a negative cycle, false otherwise

#endif // ALGORITHMS_HPP