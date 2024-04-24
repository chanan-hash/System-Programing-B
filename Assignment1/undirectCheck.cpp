#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace ariel;
using namespace std;
/**
 * This file is for checking the undirected graph algorithms
 */

int main()
{
    ariel::Graph g;

    // for now we are assuming that the graph is undirected just for the checkups
    // vector<vector<int>> graph = {{0, 1}, {1, 0}};
    // g.loadGraph(graph);
    // g.printGraph();

    // cout << Algorithms::isConnected(g) << endl; // true
    // cout << Algorithms::isContainsCycle(g) << endl; // false

    vector<vector<int>> graph1 = {{0, 2}, {2, 0}};
    g.loadGraph(graph1);
    g.printGraph();

    cout << Algorithms::isConnected(g) << endl; // true
    cout << Algorithms::isContainsCycle(g) << endl; // false

    // vector<vector<int>> graph2 = {
    //     {0, 1, 0},
    //     {1, 0, 1},
    //     {0, 1, 0}};

    return 0;
}