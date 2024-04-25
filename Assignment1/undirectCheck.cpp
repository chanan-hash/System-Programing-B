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
    /**
     * Chechups for undirected and unweighted graph
     */
    // for now we are assuming that the graph is undirected just for the checkups
    // vector<vector<int>> graph = {{0, 1}, {1, 0}};
    // g.loadGraph(graph);
    // g.printGraph();

    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 1) << endl; // 0->1
    // cout << Algorithms::shortestPath(g, 1, 0) << endl; // 0->1
    // cout << Algorithms::shortestPath(g, 1, 2) << endl; // no path

    // vector<vector<int>> graph1 = {{0, 2}, {2, 0}};
    // g.loadGraph(graph1);
    // g.printGraph();

    // cout << Algorithms::isConnected(g) << endl; // true
    // cout << Algorithms::isContainsCycle(g) << endl; // false
    // cout << Algorithms::whatGraph(g) << endl; // false

    // vector<vector<int>> graph2 = {
    //     {0, 1, 0},
    //     {1, 0, 1},
    //     {0, 1, 0}};

    // vector<vector<int>> graph3{
    //     {0, 1, 0, 1, 0},
    //     {1, 0, 1, 0, 0},
    //     {0, 1, 0, 1, 1},
    //     {1, 0, 1, 0, 0},
    //     {0, 0, 1, 0, 0}};
    // g.loadGraph(graph3);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // true
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // 0-> 1 -> 2 -> 4
    // cout << Algorithms::shortestPath(g, 3, 1) << endl; //  3 -> 0 -> 1

    /** Checking weighted undirect graphs*/
    vector<vector<int>> graph4{
        {0, 10, 0, 5, 0},
        {10, 0, 6, 0, 0},
        {0, 6, 0, 0, 0},
        {5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    g.printGraph();
    cout << Algorithms::isConnected(g) << endl;        // false
    cout << Algorithms::isContainsCycle(g) << endl;    // false
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // no path
    cout << Algorithms::shortestPath(g, 1, 2) << endl; // 1 -> 2

    return 0;
}