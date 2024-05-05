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
    ariel::Graph g(false);
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
    // cout << Algorithms::shortestPath(g, 1, 0) << endl; // 1->0
    // cout << Algorithms::shortestPath(g, 1, 2) << endl; // no path

    // vector<vector<int>> graph1 = {{0, 2}, {2, 0}};
    // g.loadGraph(graph1);
    // g.printGraph();

    // cout << Algorithms::isConnected(g) << endl; // true
    // cout << Algorithms::isContainsCycle(g) << endl; // false
    // cout << Algorithms::whatGraph(g) << endl; // false

    // vector<vector<int>> graph2 = {
    //     {0, 1},
    //     {1, 0}};
    // g.loadGraph(graph2);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 1) << endl; // 0->1
    // cout << Algorithms::shortestPath(g, 1, 0) << endl; // 0->1
    // cout << Algorithms::isBipartite(g) << endl;        // {0} {1}

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
    // cout << Algorithms::isBipartite(g) << endl; 
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
    // cout << Algorithms::negativeCycle(g) << endl;      // 
        //     // if we'll change place [3][1] = 0 we'll get 0 -> 1 -> 3 -> 4

    // have negative cycle
    // vector<vector<int>> graph6 = {
    //     {0, -1, 0, -1, 0},
    //     {-1, 0, -1, 0, 0},
    //     {0, -1, 0, 0, -1},
    //     {-1, 0, 0, 0, -1},
    //     {0, 0, -1, -1, 0}};
    // g.loadGraph(graph6);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;     // true
    // cout << Algorithms::isContainsCycle(g) << endl; // true
    // cout << Algorithms::shortestPath(g, 2, 4) << endl; // we have a negative cycle, because we can go from vertex 1 to 3 (2 to 4) as many times as we want
    // cout << Algorithms::negativeCycle(g) << endl; // true

    // vector<vector<int>> graph7 = {
    //     {0, 1, 0, 1, 0, 0},
    //     {1, 0, 1, 0, 0, 0},
    //     {0, 1, 0, 1, 0, 0},
    //     {1, 0, 1, 0, 1, 0},
    //     {0, 0, 0, 1, 0, 1},
    //     {0, 0, 0, 0, 1, 0}};

    // g.loadGraph(graph7);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // true
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // 0 -> 3 -> 4
    // cout << Algorithms::negativeCycle(g) << endl;      // false
    // cout << Algorithms::isBipartite(g) << endl;        // {1,3,5} {0,2,4}

    // vector<vector<int>> graph7 = {
    //     {0, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 0}};

    // g.loadGraph(graph7);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // true
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // not found
    // cout << Algorithms::shortestPath(g, 0, 2) << endl; // 0 -> 2
    // cout << Algorithms::negativeCycle(g) << endl;      // false
    // cout << Algorithms::isBipartite(g) << endl;        // not bipartite

    // vector<vector<int>> graph8 = {
    //     {0, 1, 1, 1, 0},
    //     {1, 0, 1, 0, 1},
    //     {1, 1, 0, 1, 1},
    //     {1, 0, 1, 0, 0},
    //     {0, 1, 1, 0, 0}};

    // g.loadGraph(graph8);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // true
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // not found
    // cout << Algorithms::shortestPath(g, 0, 2) << endl; // 0 -> 2
    // cout << Algorithms::negativeCycle(g) << endl;      // false
    // cout << Algorithms::isBipartite(g) << endl;        // not bipartite

    // A graph the non- of the vertices are connected
    // vector<vector<int>> graph9 = {
    //     {0,0,0,0},
    //     {0,0,0,0},
    //     {0,0,0,0},
    //     {0,0,0,0}
    // };

    // g.loadGraph(graph9);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // false
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 3) << endl; // not found
    // cout << Algorithms::shortestPath(g, 0, 0) << endl; // not found
    // cout << Algorithms::negativeCycle(g) << endl;      // false
    // cout << Algorithms::isBipartite(g) << endl;        // bipartite in how many ways

    // checking the graph with 1 vertex
    // vector<vector<int>> graph10 = {
    //     {0}};
    // g.loadGraph(graph10);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 0) << endl; // 0
    // cout << Algorithms::shortestPath(g, 0, 2) << endl;
    // cout << Algorithms::negativeCycle(g) << endl; // false
    // cout << Algorithms::isBipartite(g) << endl;   // only one vertex

    // checking the graph with 1 vertex that is not connected
    // vector<vector<int>> graph11 = {
    //     {0, 1, 0},
    //     {1, 0, 0},
    //     {0, 0, 0}};

    // g.loadGraph(graph11);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // false
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 2) << endl; // not found
    // cout << Algorithms::shortestPath(g, 1, 0) << endl; // 1->0
    // cout << Algorithms::negativeCycle(g) << endl;      // false
    // cout << Algorithms::isBipartite(g) << endl;        // {0, 2} {1}

    //    checking the graph with 5 vertices that has 2 connected components
    // vector<vector<int>> graph12 = {
    //     {0, 1, 0, 0, 0},
    //     {1, 0, 0, 0, 0},
    //     {0, 0, 0, 1, 2},
    //     {0, 0, 1, 0, 0},
    //     {0, 0, 2, 0, 0}};
    // g.loadGraph(graph12);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // false
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // not found
    // cout << Algorithms::shortestPath(g, 1, 2) << endl; // not found
    // cout << Algorithms::shortestPath(g, 4, 3) << endl; // 4 -> 2 -> 3
    // cout << Algorithms::shortestPath(g, 1, 0) << endl; // 1 -> 0
    // cout << Algorithms::negativeCycle(g) << endl;      // false
    // cout << Algorithms::isBipartite(g) << endl;        // A={0, 2}, B={1, 3, 4}

    // checking the graph with 5 vertices that 2 of them are not connected to any other vertex
    // vector<vector<int>> graph13 = {
    //     {0, 1, 0, 1, 0},
    //     {1, 0, 0, 2, 0},
    //     {0, 0, 0, 0, 0},
    //     {1, 2, 0, 0, 0},
    //     {0, 0, 0, 0, 0}};
    // g.loadGraph(graph13);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // false
    // cout << Algorithms::isContainsCycle(g) << endl;    // true 0 -> 1 -> 3 -> 0
    // cout << Algorithms::shortestPath(g, 0, 3) << endl; // 0 -> 3
    // cout << Algorithms::shortestPath(g, 1, 2) << endl; // not found
    // cout << Algorithms::negativeCycle(g) << endl;      // false
    // cout << Algorithms::isBipartite(g) << endl;        // A={0, 2, 4}, B={1,3}

    // vector<vector<int>> graph14 = {
    //     {0, 1, 0, 0, 0},
    //     {1, 0, 2, 0, 0},
    //     {0, 2, 0, 3, 0},
    //     {0, 0, 3, 0, 4},
    //     {0, 0, 0, 4, 0}
    // };
    // g.loadGraph(graph14);
    // g.printGraph();
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // 0 -> 1 -> 2 -> 3 -> 4
    // cout << Algorithms::isBipartite(g) << endl;        // {0, 2, 4} {1, 3}

    vector<vector<int>> graph15 = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, -10, 0, 0, 0, 0, 0, 0},
        {0, -10, 0, 20, 0, 0, 0, 0, 0},
        {0, 0, 20, 0, -30, 0, 0, 0, 0},
        {0, 0, 0, -30, 0, 40, 0, 0, 0},
        {0, 0, 0, 0, 40, 0, -50, 0, 10},
        {0, 0, 0, 0, 0, -50, 0, 60, 0},
        {0, 0, 0, 0, 0, 0, 60, 0, -70},
        {0, 0, 0, 0, 0, 10, 0, -70, 0}};

    g.loadGraph(graph15);
    g.printGraph();
    cout << Algorithms::isConnected(g) << endl;        // true
    cout << Algorithms::isContainsCycle(g) << endl;    // false
    cout << Algorithms::negativeCycle(g) << endl;     // true

    // vector<vector<int>> graph16 = {
    //     {0, -1, 0, 0, 0},
    //     {-1, 0, 3, 0, 0},
    //     {0, 3, 0, 4, 0},
    //     {0, 0, 4, 0, 5},
    //     {0, 0, 0, 5, 0}};
    // g.loadGraph(graph16);
    // cout << Algorithms::isConnected(g) << endl;        // true
    // cout << Algorithms::isContainsCycle(g) << endl;    // false
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; 
    // cout << Algorithms::negativeCycle(g) << endl; // negative cycle

    return 0;
}