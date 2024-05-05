#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdexcept>

using namespace doctest;
using namespace ariel;
using namespace std;

/***************** Testing Undirected graphs ********************/
TEST_CASE("Test functions for graph 1")
{
    ariel::Graph g(false); // undirected graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}.");
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "No path found");
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0 -> 1 -> 2");
}

TEST_CASE("Test undirected cycle graph")
{
    ariel::Graph g(false); // undirected graph
    vector<vector<int>> graph7 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0 -> 2");
}

TEST_CASE("Testing two simple small graphs")
{
    ariel::Graph g(false);
    vector<vector<int>> graph = {{0, 1}, {1, 0}};

    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}.");
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::shortestPath(g, 0, 1) == "0 -> 1");
    CHECK(Algorithms::shortestPath(g, 1, 0) == "1 -> 0");
    CHECK(Algorithms::shortestPath(g, 1, 2) == "No path found"); // vertex bigger than the graph size
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}.");

    vector<vector<int>> graph1 = {{0, 2}, {2, 0}}; // the same but weights
    g.loadGraph(graph1);

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}.");
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::shortestPath(g, 0, 1) == "0 -> 1");
    CHECK(Algorithms::shortestPath(g, 1, 0) == "1 -> 0");
}

TEST_CASE("Checking bigger graph")
{
    ariel::Graph g(false);
    vector<vector<int>> graph3{
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3, 4}.");
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0 -> 1 -> 2 -> 4");
    CHECK(Algorithms::shortestPath(g, 3, 1) == "3 -> 0 -> 1");
}

/*********** Weighted undirected graphs *********/
TEST_CASE("Testin weighted undirected graphs")
{
    ariel::Graph g(false);
    vector<vector<int>> graph4{
        {0, 10, 0, 5, 0},
        {10, 0, 6, 0, 0},
        {0, 6, 0, 0, 0},
        {5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);

    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "No path found");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "1 -> 2");

    vector<vector<int>> graph14 = {
        {0, 1, 0, 0, 0},
        {1, 0, 2, 0, 0},
        {0, 2, 0, 3, 0},
        {0, 0, 3, 0, 4},
        {0, 0, 0, 4, 0}};
    g.loadGraph(graph14);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0 -> 1 -> 2 -> 3 -> 4");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}.");

    vector<vector<int>> graph15 = {
        {0, 1, 0, 0, 0},
        {1, 0, 2, 8, 0},
        {0, 2, 0, 3, 0},
        {0, 8, 3, 0, 4},
        {0, 0, 0, 4, 0}};
    g.loadGraph(graph15);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0 -> 1 -> 2 -> 3 -> 4");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "1 -> 2 -> 3");
}

TEST_CASE("Checking unconccted undirected graphs")
{
    ariel::Graph g(false);

    // Graph with no edges
    vector<vector<int>> graph9 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph9);

    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "No path found");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "No path found");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2, 3}, B={}.");

    // Graph with one vertex
    vector<vector<int>> graph10 = {
        {0}};
    g.loadGraph(graph10);

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={}.");

    // checking the graph with 1 vertex that is not connected
    vector<vector<int>> graph11 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};

    g.loadGraph(graph11);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "No path found");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == "1 -> 0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}.");

    // Checking graph with 2 connected components
    vector<vector<int>> graph12 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 2},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0}};
    g.loadGraph(graph12);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "No path found");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "No path found");
    CHECK(ariel::Algorithms::shortestPath(g, 4, 3) == "4 -> 2 -> 3");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == "1 -> 0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3, 4}.");
}

// TEST_CASE("Testing undirected with negative edges graphs")
// {
// }

/***************** Testing Directed graphs ********************/

/***************** Testin their graphs ****************/
//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isConnected(g) == false);
// }

// TEST_CASE("Test shortestPath")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
// }
// TEST_CASE("Test isContainsCycle")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);

//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);
// }
// TEST_CASE("Test isBipartite")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isBipartite(g) == "0");

//     vector<vector<int>> graph3 = {
//         {0, 1, 2, 0, 0},
//         {1, 0, 3, 0, 0},
//         {2, 3, 0, 4, 0},
//         {0, 0, 4, 0, 5},
//         {0, 0, 0, 5, 0}};
//     g.loadGraph(graph3);
//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
// }

// TEST_CASE("Test invalid graph")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 2, 0},
//         {1, 0, 3, 0},
//         {2, 3, 0, 4},
//         {0, 0, 4, 0},
//         {0, 0, 0, 5}};
//     CHECK_THROWS(g.loadGraph(graph));
// }
