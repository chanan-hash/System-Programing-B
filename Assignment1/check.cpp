#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;

int main()
{

    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

    cout << graph.size() << endl;
    cout << graph[0].size() << endl;

    cout << "Trying to print the graph"<< endl;

    Graph g;
    g.loadGraph(graph);
    g.printGraph();

    return 0;
}