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
        vector<vector<int>> getAdjMatrix() const;
        bool getDirected() const;

        void setDirected(bool isDirected);

        // Function to load graph from an adjacency matrix, like a set function
        void loadGraph(vector<vector<int>> &matrix); // passing it not by reference because we don't want to change it the orginal matrix

        // Function to print the adjacency matrix
        void printGraph();

        static bool isSymetric(vector<vector<int>> &matrix); // getting a matrix and return if it is symmetric

        /********************* Operator overloading ************************/
        // The + operator
        Graph operator+(const Graph &other);
        Graph &operator+=(const Graph &other);
        Graph operator+() const; // unary plus operator

        // The - operator
        Graph operator-(const Graph &other);
        Graph &operator-=(const Graph &other);
        Graph operator-() const; // unary minus operator

        // The * operator

        Graph operator*(const Graph &other) const;
        Graph operator*(const int num) const;
        Graph &operator*=(const int &num);

        Graph &operator/=(const int &num);

        // The equality operators
        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other) const;
        bool operator<(const Graph &other) const;
        bool operator>(const Graph &other) const;
        bool operator<=(const Graph &other) const;
        bool operator>=(const Graph &other) const;

        // increment and decrement operators
        // int parameter is a dummy parameter used to differentiate this method from the prefix version.
        Graph &operator++();   // prefix increment operator
        Graph operator++(int); // postfix increment operator

        Graph &operator--();   // prefix decrement operator
        Graph operator--(int); // postfix decrement operator

        // This will allow us to do cout<<g1
        // The friends means this is not a class function, so it can take more arguments,
        // and it has accsses to private members of the class.
        friend std::ostream &operator<<(std::ostream &os, const Graph &g);
    };
    // int * Graph
    Graph operator*(int num, const Graph &g);

} // namespace ariel
#endif // GRAPH_HPP
