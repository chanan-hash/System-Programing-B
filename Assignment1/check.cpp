#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace ariel;
using namespace std;

int main()
{
     ariel::Graph g;

     // vector<vector<int>> graph = {
     //     {0, 1, 0},
     //     {1, 0, 1},
     //     {0, 1, 0}};

     // cout << graph.size() << endl;
     // cout << graph[0].size() << endl;

     // cout << "Trying to print the graph" << endl;

     // g.loadGraph(graph);
     // g.printGraph();

     // cout << "Printing is the graph is connected or not: 0 for false, 1 for true"<< endl;
     // cout << Algorithms::isConnected(g) << endl;

     // cout << "Printing the shortest path from 0 to 2\n"
     //      << endl;
     // cout << Algorithms::shortestPath(g, 0, 2) << endl;
     // cout << "is cycle: " << Algorithms::isContainsCycle(g) << endl; // Should print: "0" (false).
     // cout << Algorithms::isBipartite(g) << endl;                     // Should print: "The graph is bipartite: A={0, 2}, B={1}."

     // vector<vector<int>> graph2 = {
     //     {0, 1, 1, 0, 0},
     //     {1, 0, 1, 0, 0},
     //     {1, 1, 0, 1, 0},
     //     {0, 0, 1, 0, 0},
     //     {0, 0, 0, 0, 0}};

     // g.loadGraph(graph2); // Load the graph to the object.
     // cout << "\nPrinting the graph2" << endl;

     // g.printGraph();
     // cout << "Printing is the graph is connected or not: 0 for false, 1 for true\n"
     //      << endl;
     // cout << Algorithms::isConnected(g) << endl;

     // cout << "Printing the shortest path from 0 to 4\n"
     //      << endl;
     // cout << Algorithms::shortestPath(g, 0, 4) << endl;              // should print -1
     // cout << "is cycle: " << Algorithms::isContainsCycle(g) << endl; // Should print: "1" true.

     // cout << "\n printing graph3\n"
     //      << endl;
     // cout << Algorithms::isBipartite(g) << endl; // Should print: "0" (false).

     // vector<vector<int>> graph3 = {
     //     {0, 1, 2, 0, 0},
     //     {1, 0, 3, 0, 0},
     //     {2, 3, 0, 4, 0},
     //     {0, 0, 4, 0, 5},
     //     {0, 0, 0, 5, 0}};
     // g.loadGraph(graph3); // Load the graph to the object.

     // g.printGraph(); // Should print: "Graph with 5 vertices and 7 edges."
     // cout << "\n"
     //      << endl;
     // cout << Algorithms::isConnected(g) << endl; // Should print: "1" (true).

     // cout << "\nPrinting the shortest path from 0 to 4"
     //      << endl;
     // cout << Algorithms::shortestPath(g, 0, 4) << endl;              // Should print: 0->1->2->3->4.
     // cout << "is cycle: " << Algorithms::isContainsCycle(g) << endl; // Should print: "1" true.
     // cout << Algorithms::isBipartite(g) << endl;                     // Should print: "The graph is bipar/ite: A={0, 2, 4}, B={1, 3}."
     // to make it bipart we need to change there the 2 to 0

     // vector<vector<int>> graph = {{0, 0, 1, 2, 3},
     //                              {0, 0, 1, 0, 0},
     //                              {1, 0, 0, 1, 0},
     //                              {2, 0, 0, 0, 1},
     //                              {3, 1, 0, 0, 0}};
     // g.loadGraph(graph);
     // g.printGraph();
     // cout << "is cycle: " << Algorithms::isContainsCycle(g) << endl; // 0 -> 2 -> 3 -> 0
     // cout << Algorithms::shortestPath(g, 4, 3) << endl; // 4 -> 1 -> 2 -> 3
     // cout << Algorithms::isBipartite(g) << endl; // The graph is not bipartite
     // cout << Algorithms::isConnected(g) << endl; // The graph is connected

     // vector<vector<int>> graph = {{0, 0, 0, 2, 3},
     //                              {0, 0, 1, 0, 0},
     //                              {0, 0, 0, 0, 0},
     //                              {2, 0, 0, 0, 1},
     //                              {3, 0, 0, 0, 0}};
     // g.loadGraph(graph);
     // g.printGraph();
     // cout << "is cycle: " << Algorithms::isContainsCycle(g) << endl;
     // cout << Algorithms::isConnected(g) << endl;
     // cout << Algorithms::shortestPath(g, 1, 2) << endl;
     // cout << Algorithms::shortestPath(g, 0, 4) << endl;

     // vector<vector<int>> graph = {{0, 0, 1, 2},
     //                              {0, 0, 2, -1},
     //                              {1, 0, 0, 3},
     //                              {2, -1, 0, 0}};
     // g.loadGraph(graph);
     // g.printGraph();
     // cout << "is cycle: " << Algorithms::isContainsCycle(g) << endl;
     // cout << Algorithms::isConnected(g) << endl;
     // cout << Algorithms::shortestPath(g, 2, 3) << endl;
     // cout << Algorithms::negativeCycle(g) << endl; // yes

     vector<vector<int>> graph5 = {{0, 1}, {1, 0}};
     // doesn't detect a cycle
     // vector<vector<int>> graph5 = {{0, 1}, {-1, 0}};
     // vector<vector<int>> graph5 = {{0, 1}, {2, 0}};

     g.loadGraph(graph5);
     g.printGraph();
     cout << "is cycle: " << Algorithms::isContainsCycle(g) << endl;
     cout << Algorithms::shortestPath(g, 0, 1) << endl; 
     return 0;
}