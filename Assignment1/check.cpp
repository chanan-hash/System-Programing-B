#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <string>

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
     // cout << Algorithms::isBipartite(g) << endl;      // false
     // cout << Algorithms::shortestPath(g, 0, 2) << endl;
     // cout << Algorithms::shortestPath(g, 2, 1) << endl;
     // cout << Algorithms::shortestPath(g, 1, 2) << endl;

     // vector<vector<int>> graph2 = {
     //     {0, 1, 0},
     //     {0, 0, 1},
     //     {0, 0, 0}};
     // g.loadGraph(graph2);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // false
     // cout << Algorithms::isBipartite(g) << endl;      // A={0, 2}, B={1}.
     // cout << Algorithms::shortestPath(g, 0, 2) << endl; // 0 -> 1 -> 2
     // cout << Algorithms::shortestPath(g, 1, 2) << endl; // 1 -> 2
     // cout << Algorithms::shortestPath(g, 2, 1) << endl; // no path
     // cout << Algorithms::shortestPath(g, 2, 0) << endl; // no path

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
     // cout << Algorithms::isContainsCycle(g) << endl;    // true because it is directed graph
     // cout << Algorithms::isBipartite(g) << endl;        // A={0, 2}, B={1}.
     // cout << Algorithms::shortestPath(g, 0, 2) << endl; // 0 -> 1 -> 2
     // cout << Algorithms::shortestPath(g, 2, 0) << endl; // 2 -> 1 -> 0

     // vector<vector<int>> graph5 = {
     //     {0, 1, 0, 0, 0},
     //     {1, 0, 2, 0, 0},
     //     {0, 2, 0, 3, 0},
     //     {0, 0, 3, 0, 4},
     //     {0, 0, 0, 4, 0}};
     // g.loadGraph(graph5);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // false

     // vector<vector<int>> graph5 = {
     //     {0, 1, 0, 0, 0},
     //     {0, 0, 2, 0, 0},
     //     {0, 0, 0, 3, 0},
     //     {0, 0, 0, 0, 4},
     //     {0, 0, 0, 0, 0}};
     // g.loadGraph(graph5);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // false
     // cout << Algorithms::isBipartite(g) << endl;      // A={0, 2, 4}, B={1, 3}.

     /****** unwighted directed graphs: *******/

     // graph with no edges
     // vector<vector<int>> graph6 = {
     //     {0, 0, 0, 0, 0},
     //     {0, 0, 0, 0, 0},
     //     {0, 0, 0, 0, 0},
     //     {0, 0, 0, 0, 0},
     //     {0, 0, 0, 0, 0}};
     // g.loadGraph(graph6);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // false
     // cout << Algorithms::isBipartite(g) << endl;      // A={0, 1, 2, 3, 4}, B={}.
     // cout << Algorithms::shortestPath(g, 0, 2) << endl; // no path
     // cout << Algorithms::shortestPath(g, 2, 0) << endl; // no path
     // cout << Algorithms::shortestPath(g, 3, 1) << endl; // no path
     // cout << Algorithms::shortestPath(g, 4, 2) << endl; // no path

     // graph with vertices that are not connected to any body with no cycles
    
     // HAVE BUGS HERE RETRURNING CYCLE AND NOT BIPARTITE- BUT NOT SUPPOSED TO
     // vector<vector<int>> graph6 = {
     //     {0, 1, 0, 0, 0, 0, 0},
     //     {0, 0, 1, 0, 0, 0, 0},
     //     {0, 0, 0, 1, 0, 0, 0},
     //     {0, 0, 0, 0, 1, 0, 0},
     //     {0, 0, 0, 0, 0, 0, 0},
     //     {0, 0, 0, 0, 0, 0, 0},
     //     {1, 0, 0, 0, 0, 0, 0}};
     // g.loadGraph(graph6);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // false  
     // cout << Algorithms::isBipartite(g) << endl;      // 
     // cout << Algorithms::shortestPath(g, 5, 3) << endl; // no path
     // cout << Algorithms::shortestPath(g, 2, 6) << endl; // no path
     // cout << Algorithms::shortestPath(g, 0, 5) << endl; // no path
     // cout << Algorithms::shortestPath(g, 6, 4) << endl; // 6 -> 0 -> 1 -> 2 -> 3 -> 4


     //      vector<vector<int>> graph7 = {
     //     {0, 1, 0, 0, 0, 0, 0},
     //     {0, 0, 1, 0, 0, 0, 0},
     //     {0, 0, 0, 1, 0, 0, 0},
     //     {0, 0, 0, 0, 1, 0, 0},
     //     {0, 1, 0, 0, 0, 0, 0},
     //     {0, 0, 0, 0, 0, 0, 0},
     //     {1, 0, 0, 0, 0, 0, 0}};
     // g.loadGraph(graph7);
     // g.printGraph();
     // cout << Algorithms::isContainsCycle(g) << endl; // true 1->2->3->4->1  
     // cout << Algorithms::isBipartite(g) << endl;      // ?
     // cout << Algorithms::shortestPath(g, 5, 3) << endl; // no path
     // cout << Algorithms::shortestPath(g, 2, 6) << endl; // no path
     // cout << Algorithms::shortestPath(g, 0, 5) << endl; // no path
     // cout << Algorithms::shortestPath(g, 6, 4) << endl; // 6 -> 0 -> 1 -> 2 -> 3 -> 4
     // cout << Algorithms::shortestPath(g, 4, 1) << endl; // 4 -> 1
     // cout << Algorithms::shortestPath(g, 1, 4) << endl; // 1 -> 2 -> 3 -> 4
     








     // graph with few connected components

     return 0;
}