#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace ariel::Algorithms;
using namespace std;

int main()
{

     vector<vector<int>> graph = {
         {0, 1, 0},
         {1, 0, 1},
         {0, 1, 0}};

     cout << graph.size() << endl;
     cout << graph[0].size() << endl;

     cout << "Trying to print the graph" << endl;

     ariel::Graph g;
     g.loadGraph(graph);
     g.printGraph();

     cout << "Printing is the graph is connected or not: 0 for false, 1 for true\n"
          << endl;
     cout << Algorithms::isConnected(g) << endl;

     cout << "Printing the shortest path from 0 to 2\n"
          << endl;
     cout << Algorithms::shortestPath(g, 0, 2) << endl;
     cout << "is cycle: " << Algorithms::isContainsCycle(g) << endl;

     vector<vector<int>> graph2 = {
         {0, 1, 1, 0, 0},
         {1, 0, 1, 0, 0},
         {1, 1, 0, 1, 0},
         {0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0}};

     g.loadGraph(graph2); // Load the graph to the object.
     cout << "\nPrinting the graph2" << endl;

     g.printGraph();
     cout << "Printing is the graph is connected or not: 0 for false, 1 for true\n"
          << endl;
     cout << Algorithms::isConnected(g) << endl;

     cout << "Printing the shortest path from 0 to 4\n"
          << endl;
     cout << Algorithms::shortestPath(g, 0, 4) << endl; // should print -1

     cout << "\n printing graph3\n"
          << endl;
     vector<vector<int>> graph3 = {
         {0, 1, 2, 0, 0},
         {1, 0, 3, 0, 0},
         {2, 3, 0, 4, 0},
         {0, 0, 4, 0, 5},
         {0, 0, 0, 5, 0}};
     g.loadGraph(graph3); // Load the graph to the object.

     g.printGraph(); // Should print: "Graph with 5 vertices and 7 edges."
     cout << "\n"
          << endl;
     cout << Algorithms::isConnected(g) << endl; // Should print: "1" (true).

     cout << "\nPrinting the shortest path from 0 to 4"
          << endl;
     cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->1->2->3->4.

     return 0;
}