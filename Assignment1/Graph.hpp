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
    // Empty Constructor
    Graph();

    // Function to load graph from an adjacency matrix
    void loadGraph(vector<vector<int>>& matrix);

    // Function to print the adjacency matrix
    void printGraph();
};

#endif // GRAPH_HPP
