// mail - chanahelamn@gmail.com
// Author - Chanan helman

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        vector<vector<int>> adjMatrix;
        size_t numVertices;
        bool isDirected;

    public:
        // Constructor that getting  if the graph is directed or not
        Graph(bool isDirected = false); // default constructor is not directed

        size_t getNumVertices() const;
        vector<vector<int>> getAdjMatrix();
        bool getDirected() const;

        void setDirected(bool isDirected);

        // Function to load graph from an adjacency matrix, like a set function
        void loadGraph(vector<vector<int>> &matrix); // passing it not by reference because we don't want to change it the orginal matrix

        // Function to print the adjacency matrix
        void printGraph();

        static bool isSymetric(vector<vector<int>> &matrix); // getting a matrix and return if it is symmetric
    };
} // namespace ariel

#endif // GRAPH_HPP