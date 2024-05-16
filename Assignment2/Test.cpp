#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    ariel::Graph g4;
    g4.loadGraph(expectedGraph);
    CHECK((g3 == g4) == true);
    CHECK((&g3 != &g1) == true);

    SUBCASE("Test graph addition with assignment")
    {
        g1 += g2;
        CHECK((g1 == g4) == true);
        CHECK((g1 != g3) == false);
    }

    SUBCASE("Test unary +")
    {
        ariel::Graph g5 = +g1;
        CHECK((g5 == g1) == true);
    }

    SUBCASE("Addition of two graphs with different dimensions")
    {
        ariel::Graph g6;
        vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
        g6.loadGraph(graph2);
        CHECK_THROWS(g1 + g6);
        CHECK_THROWS(g1 += g6);
    }

    SUBCASE("Test algorithms")
    {
        CHECK(g3.getDirected() == false);
        CHECK(ariel::Algorithms::isConnected(g3) == true);
        CHECK(ariel::Algorithms::isContainsCycle(g3) == true);
        CHECK(ariel::Algorithms::isBipartite(g3) == "The graph is not bipartite");
        CHECK(ariel::Algorithms::shortestPath(g3, 1, 2) == "1 -> 2");
    }
}

TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;

    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    ariel::Graph g4;
    g4.loadGraph(expectedGraph);
    CHECK((g3 == g4) == true);

    SUBCASE("Test graph subtraction with assignment")
    {
        g1 -= g2;
        CHECK((g1 == g4) == true);
        CHECK((g1 != g3) == false);
    }

    SUBCASE("Test unary -")
    {
        g1 -= g2;
        ariel::Graph g5 = -g1;
        g4 = -g4;
        CHECK((g5 == g4) == true);

        g5 = -g5;
        vector<vector<int>> unsignedGraph = {
            {0, 0, 1},
            {0, 0, 1},
            {1, 1, 0}};
        ariel::Graph g6;
        g6.loadGraph(unsignedGraph);
        CHECK((g5 == g1) == true);
    }

    SUBCASE("Subtraction of two graphs with different dimensions")
    {
        ariel::Graph g6;
        vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
        g6.loadGraph(graph2);
        CHECK_THROWS(g1 - g6);
        CHECK_THROWS(g1 -= g6);
    }
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    ariel::Graph g5;
    g5.loadGraph(expectedGraph);
    CHECK((g4 == g5) == true);

    SUBCASE("Test graph multiplication by scalar")
    {
        g2 *= 2;
        vector<vector<int>> expectedGraph = {
            {0, 2, 2},
            {2, 0, 4},
            {2, 4, 0}};
        ariel::Graph g6;
        g6.loadGraph(expectedGraph);
        CHECK((g2 == g6) == true);

        g2 /= 2;

        ariel::Graph g7 = 2 * g2;
        CHECK((g7 == g6) == true);

        ariel::Graph g8 = g2 * 2;
        CHECK((g8 == g6) == true);
    }

    SUBCASE("Test a big weighted graphs multiplication")
    {
        ariel::Graph g9;
        vector<vector<int>> weightedGraph2 = {
            {0, 1, 1, -1, 1},
            {1, 0, -7, 1, 4},
            {-25, 1, 0, 2, 1},
            {1, 5, 1, 0, 1},
            {9, 1, 1, 3, 0}};
        g9.loadGraph(weightedGraph2);

        vector<vector<int>> weightedGraph3 = {
            {0, -8, 1, -1, 0},
            {1, 0, -7, 1, 4},
            {-10, 1, 0, 6, 0},
            {1, 0, 4, 0, 2},
            {9, 1, -2, 3, 0}};
        ariel::Graph g10;
        g10.loadGraph(weightedGraph3);
        ariel::Graph g11 = g9 * g10;
        vector<vector<int>> expectedGraph2 = {
            {0, 2, -13, 10, 2},
            {107, 0, -3, -31, 2},
            {12, 201, 0, 29, 8},
            {4, -6, -36, 0, 20},
            {-6, -71, 14, -2, 0}};
        ariel::Graph g12;
        g12.loadGraph(expectedGraph2);
        CHECK((g11 == g12) == true);
    }
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    // CHECK_THROWS(g1 * g2); not suppoesed to throw

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
    CHECK_THROWS(g1 - g6);
}

TEST_CASE("Testing increment and decrement prefix and postfix")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    SUBCASE("Incrementing zero matrix")
    {
        vector<vector<int>> zeroMatrix = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
        ariel::Graph g3;
        g3.loadGraph(zeroMatrix);
        // Not supposed to change the graph
        g3++;
        ++g3;
        ariel::Graph g4; 
        g4.loadGraph(zeroMatrix);
        CHECK((g3 == g4) == true);
        CHECK((g3 != g4) == false);
    }
}