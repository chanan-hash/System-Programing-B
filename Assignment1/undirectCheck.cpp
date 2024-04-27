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
    // vector<vector<int>> graph4{
    //     {0, 10, 0, 5, 0},
    //     {10, 0, 6, 0, 0},
    //     {0, 6, 0, 0, 0},
    //     {5, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0}};
    // g.loadGraph(graph4);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // false
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // no path
    // cout << Algorithms::shortestPath(g, 1, 2) << endl; // 1 -> 2

    /*** Checking weighted undirect graphs with negative edges ****/
    // vector<vector<int>> graph5{
    //     {0, 6, 7, 0, 0},
    //     {6, 0, 8, -4, 0},
    //     {7, 8, 0, 0, 5},
    //     {0, -4, 0, 0, 7},
    //     {0, 0, 5, 7, 0}};
    // g.loadGraph(graph5);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // true
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // we have a negative cycle, because we can go from vertex 1 to 3 (2 to 4) as many times as we want
    //     // if we'll change place [3][1] = 0 we'll get 0 -> 1 -> 3 -> 4

    // have negative cycle
    vector<vector<int>> graph6 = {
        {0, -1, 0, -1, 0},
        {-1, 0, -1, 0, 0},
        {0, -1, 0, 0, -1},
        {-1, 0, 0, 0, -1},
        {0, 0, -1, -1, 0}};
    g.loadGraph(graph6);
    g.printGraph();
    cout << Algorithms::isConnected(g) << endl;     // true
    cout << Algorithms::isContainsCycle(g) << endl; // true
    cout << Algorithms::shortestPath(g, 2, 4) << endl; // we have a negative cycle, because we can go from vertex 1 to 3 (2 to 4) as many times as we want
    cout << Algorithms::negativeCycle(g) << endl; // true
    return 0;
}