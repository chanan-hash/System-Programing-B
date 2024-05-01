#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace ariel;
using namespace std;

int main()
{
     ariel::Graph g;
     // vector<vector<int>> graph1 = {
     //     {0, 1, 0},
     //     {0, 0, 1},
     //     {1, 0, 0}};
     // g.loadGraph(graph1);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // true 0 -> 1 -> 2 -> 0

     // vector<vector<int>> graph2 = {
     //     {0, 1, 0},
     //     {0, 0, 1},
     //     {0, 0, 0}};
     // g.loadGraph(graph2);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // false

     // vector<vector<int>> graph3 = {
     //     {0, 1, 0},
     //     {3, 0, 1},
     //     {0, 2, 0}};

     // g.loadGraph(graph3);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // returning 0, it thinks that is undirected graph

     // vector<vector<int>> graph4 = {
     //     {0, 1, 0},
     //     {1, 0, 1},
     //     {0, 1, 0}};
     // g.loadGraph(graph4);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // false

     // vector<vector<int>> graph5 = {
     //     {0, 1, 0, 0, 0},
     //     {1, 0, 2, 0, 0},
     //     {0, 2, 0, 3, 0},
     //     {0, 0, 3, 0, 4},
     //     {0, 0, 0, 4, 0}};
     // g.loadGraph(graph5);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // false

     vector<vector<int>> graph5 = {
         {0, 1, 0, 0, 0},
         {0, 0, 2, 0, 0},
         {0, 0, 0, 3, 0},
         {0, 0, 0, 0, 4},
         {0, 0, 0, 0, 0}};
     g.loadGraph(graph5);
     g.printGraph();
     cout << Algorithms::isContainsCycle(g) << endl; // false
     return 0;
}