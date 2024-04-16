#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace std;
// using namespace Algorithms;

int main()
{

    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

    cout << graph.size() << endl;
    cout << graph[0].size() << endl;

    cout << "Trying to print the graph" << endl;

    Graph g;
    g.loadGraph(graph);
    g.printGraph();

    cout << "Printing is the graph is connected or not: 0 for false, 1 for true\n" << endl;
    cout << isConnected(g) << endl;


    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.
    cout << "\nPrinting the graph2" << endl;

    g.printGraph();
    cout << "Printing is the graph is connected or not: 0 for false, 1 for true\n" << endl;
    cout << isConnected(g) << endl;
    return 0;
}