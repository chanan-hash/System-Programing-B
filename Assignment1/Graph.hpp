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
        bool isDirected = false; // assuming false

    public:
        // Empty Constructor
        Graph(bool isDirected = false); // default constructor by creating the graph we'll check if it is directed or not

        size_t getNumVertices();
        vector<vector<int>> getAdjMatrix();
        bool getDirected();

        // Function to load graph from an adjacency matrix, like a set function
        void loadGraph(vector<vector<int>> &matrix);

        // Function to print the adjacency matrix
        void printGraph();

        static bool isSymmetric(vector<vector<int>> &matrix); // getting a matrix and return if it is symmetric
    };
} // namespace ariel

#endif // GRAPH_HPP