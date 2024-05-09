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

size_t Graph::getNumVertices()
{
    return this->numVertices;
}

vector<vector<int>> Graph::getAdjMatrix()
{
    return this->adjMatrix;
}

bool Graph::getDirected()
{
    return this->isDirected;
}

void Graph::setDirected(bool isDirected)
{
    this->isDirected = isDirected;
}

void Graph::loadGraph(vector<vector<int>> matrix)
{
    if (!isSymetric(matrix) && !this->isDirected) // if it undirected and not symmetric
    {
        throw invalid_argument("The graph is not directed");
    }

    if (!matrix.empty())
    {
        // this->adjMatrix.clear(); // clearing all the last values in the matrix
        // Check if the matrix is square (number of rows equals number of columns)
        if (matrix.size() == matrix[(size_t)0].size()) // mattrix.at(0).size() is the number of columns
        {
            // Resize the adjacency matrix to match the input matrix
            this->adjMatrix.resize(matrix.size(), vector<int>(matrix.size()));
            // Assign each value from the input matrix to the adjacency matrix
            for (size_t i = 0; i < matrix.size(); i++)
            {
                // check if the matrix is square
                if (matrix[i].size() != matrix.size())
                {
                    throw invalid_argument("The matrix is not square");
                }

                for (size_t j = 0; j < matrix[i].size(); j++)
                {
                    if (i == j && matrix[i][j] != 0)
                    {
                        throw invalid_argument("The diagonal is not all 0's");
                    }

                    this->adjMatrix[i][j] = matrix[i][j];
                }
            }
            // Update the number of vertices
            this->numVertices = matrix.size();
        }
        else
        { // Throw an exception if the matrix is not square
            throw invalid_argument("The matrix is not square");
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