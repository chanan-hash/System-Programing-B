#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;
namespace ariel
{

    class Graph
    {
    private:
        vector<vector<int>> adjMatrix;
        size_t numVertices;

    public:
        // Empty Constructor
        // Graph();

        size_t getNumVertices();
        vector<vector<int>> getAdjMatrix();

        // Function to load graph from an adjacency matrix, like a set function
        void loadGraph(vector<vector<int>> &matrix);

        // Function to print the adjacency matrix
        void printGraph();

        bool isEdge(int vertex1, int vertex2);

        int getEdgeWeight(int vertex1, int vertex2);
    };
} // namespace ariel
#endif // GRAPH_HPP
