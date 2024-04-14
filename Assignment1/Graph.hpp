#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjMatrix;
    int numVertices;

public:
    // Constructor
    Graph(int numVertices);

    // Function to add an edge between vertices u and v with weight w
    void addEdge(int u, int v, int w);

    // Function to load graph from an adjacency matrix
    void loadGraph(vector<vector<int>>& matrix);

    // Function to print the adjacency matrix
    void printGraph();
};

#endif // GRAPH_HPP
