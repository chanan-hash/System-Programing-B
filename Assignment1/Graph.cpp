// mail - chanahelamn@gmail.com
// Author - Chanan helman

#include <iostream>
#include <vector>
#include "Graph.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;
/**
 * By using the Graph:: and include, we're refrencing the Graph class and the Graph.hpp file
 */

Graph::Graph(bool isDirected)
{
    this->isDirected = isDirected;
    this->numVertices = 0;
}

size_t Graph::getNumVertices() const
{
    return this->numVertices;
}

vector<vector<int>> Graph::getAdjMatrix() const
{
    return this->adjMatrix;
}

bool Graph::getDirected() const
{
    return this->isDirected;
}

void Graph::setDirected(bool isDirected)
{
    this->isDirected = isDirected;
}

void Graph::loadGraph(vector<vector<int>> &matrix)
{

    this->numVertices = matrix.size();
    this->adjMatrix = matrix;
    for (size_t i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[i].size() != adjMatrix.size())
        {
            throw invalid_argument("The matrix is not square");
        }
        for (size_t j = 0; j < adjMatrix[i].size(); j++)
        {
            if (i == j && adjMatrix[i][j] != 0)
            {
                throw invalid_argument("The diagonal is not all 0's");
            }
            if (!this->isDirected && adjMatrix[i][j] != adjMatrix[j][i])
            {
                throw invalid_argument("The graph is not directed");
            }
        }
    }
}

void Graph::printGraph()
{
    // for (size_t i = 0; i < this->numVertices; i++)
    // {
    //     for (size_t j = 0; j < this->numVertices; j++)
    //     {
    //         cout << this->adjMatrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int edges = 0;
    int vertices = this->numVertices;
    for (size_t i = 0; i < vertices; i++)
    {
        // only count the upper triangle of the matrix
        for (size_t j = 0; j < vertices; j++)
        {
            if (adjMatrix[i][j] != 0)
            {
                edges++;
            }
        }
    }
    if (this->isDirected)
    {
        cout << "The graph is directed. V = " << vertices << ", E = " << edges << endl;
    }
    else
    {
        cout << "The graph is undirected. V = " << vertices << " E = " << (edges / 2) << endl;
    }
}

bool Graph::isSymetric(vector<vector<int>> &matrix) // for graph being undirected it first need to be symmetric
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}