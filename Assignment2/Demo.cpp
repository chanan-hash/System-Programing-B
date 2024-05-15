/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman and Channa helman.
 * mail - chananhelman@gmail.com
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout << g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.
    cout << g2;                  // Should print the matrix of the graph: [0, 1, 1], [1, 0, 2], [1, 2, 0]

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    cout << g3;                // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    /*** my addition **********************************8*/
    g1 += g2;   // Add the two graphs together.
    cout << g1; // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1 -= g2;   // Subtract the two graphs.
    cout << g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    ariel::Graph g4 = g1 - g2; // Subtract the two graphs.
    cout << g4;                // Should print the matrix of the graph: [0, 0, -1], [-1, 0, -1], [-1, -1, 0]

    ariel::Graph g5 = -g1; // Unary minus.
    cout << g5;            // Should print the matrix of the graph: [0, -1, 0], [-1, 0, -1], [0, -1, 0]
    cout << g1;            // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    g5 = +g1;   // Unary plus.
    cout << g5; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    cout << "== operator" << endl;

    cout << (g1 == g2) << endl; // Should print 0
    cout << (g1 == g1) << endl; // Should print 1
    cout << (g1 == g5) << endl; // Should print 1
    cout << (g4 == g2) << endl; // Should print 0

    cout << "\n!= operator" << endl;

    cout << (g1 != g2) << endl; // Should print 1
    cout << (g1 != g1) << endl; // Should print 0
    cout << (g5 != g1) << endl; // Should print 0
    cout << (g4 != g2) << endl; // Should print 1

    cout << "\n* operator\n"
         << endl;

    ariel::Graph g6 = g4 * g2; // Multiply 2 graphs.
    cout << g6;

    /*************************************************/

    g1 *= -2;   // Multiply the graph by -2.
    cout << g1; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    g1 /= -2;
    cout << g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

     cout<< "g1 * 2" << endl;
     ariel::Graph g33 = g1 * 2; // Multiply the graph by 2.
     cout << g33;                // Should print the matrix of the graph: [0, 2, 0], [2, 0, 2], [0, 2, 0]

     ariel::Graph g34 = 2 * g1; // Multiply the graph by 2.
     cout << g34;                // Should print the matrix of the graph: [0, 2, 0], [2, 0, 2], [0, 2, 0]


    ariel::Graph g44 = g1 * g2; // Multiply the two graphs together.
    cout << g44;                // Should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g7;
    g7.loadGraph(graph2); // Load the graph to the object.
    try
    {
        ariel::Graph g8 = g7 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }

    // Check increment and decrement operators prefix and postfix.
    cout << "Original graph:\n"
         << g1 << endl;

    // Use the prefix ++ operator
    ++g1;
    cout << "Graph after prefix increment:\n"
         << g1 << endl;

    // Use the postfix ++ operator
    ariel::Graph g9 = g1++;
    cout << "Graph after postfix increment:\n"
         << g1 << endl;
    cout << "Copy of graph before postfix increment:\n"
         << g9 << endl;

    // Use the prefix -- operator
    cout << "Graph after prefix decrement:\n"
         << --g1 << endl;
    cout << "Original graph:\n"
         << g1 << endl;

    // Use the prefix -- operator
    // --g1;
    // cout << "Graph after prefix decrement:\n" << g1 << endl;

    // Use the postfix -- operator
    // ariel::Graph g10 = g1--;
    // cout << "Graph after postfix decrement:\n" << g1 << endl;
    // cout << "Copy of graph before postfix decrement:\n" << g10 << endl;

    // Check comparison operators.
    cout << "Comparison operators:" << endl;
    cout << "Graph g1:\n"
         << g1 << endl;
    cout << "Graph g2:\n"
         << g2 << endl;

    if (g1 < g2)
    {
        cout << "g1 is less than g2\n";
    }

    if (g1 > g2)
    {
        cout << "g1 is greater than g2\n";
    }

    if (g1 <= g2)
    {
        cout << "g1 is less than or equal to g2\n";
    }

    if (g1 >= g2)
    {
        cout << "g1 is greater than or equal to g2\n";
    }

    cout << "\nGraph g3:\n"
         << g3 << endl;

    if (g3 > g2)
    {
        cout << "g3 is greater than g2\n";
    }

    ariel::Graph g11 = +g1;

    cout << "\nGraph g1:\n"
         << g1 << endl;
    
    cout << "\nGraph g11:\n"
         << g11 << endl;

    cout << (g1 < g11) << endl; // Should print 0
    cout << (g11 < g11) << endl;
    cout << (g11 < g1) << endl;
    return 0;
}
