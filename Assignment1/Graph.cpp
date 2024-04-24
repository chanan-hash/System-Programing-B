#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;
using namespace ariel;
/**
 * By using the Graph:: and include, we're refrencing the Graph class and the Graph.hpp file
 */

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

// to do also check if the graph is directed or not by using the isSymmetric function and input from the user
void Graph::loadGraph(vector<vector<int>> &matrix)
{
    if (!matrix.empty())
    {
        // Check if the matrix is square (number of rows equals number of columns)
        if (matrix.size() == matrix[(size_t)0].size()) // mattrix.at(0).size() is the number of columns
        {
            // Resize the adjacency matrix to match the input matrix
            this->adjMatrix.resize(matrix.size(), vector<int>(matrix.size()));
            // Assign each value from the input matrix to the adjacency matrix
            for (size_t i = 0; i < matrix.size(); i++)
            {
                for (size_t j = 0; j < matrix[i].size(); j++)
                {
                    this->adjMatrix[i][j] = matrix[i][j];
                    // this->adjMatrix.at(i).at(j) = matrix.at(i).at(j);
                }
            }
            // this->adjMatrix = matrix;
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
    for (size_t i = 0; i < this->numVertices; i++)
    {
        for (size_t j = 0; j < this->numVertices; j++)
        {
            cout << this->adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool Graph::isEdge(int vertex1, int vertex2)
{
    if (vertex1 < this->numVertices && vertex2 < this->numVertices)
    {
        return this->adjMatrix[(size_t)vertex1][(size_t)vertex2] != 0;
    }
    return false;
}

int Graph::getEdgeWeight(int vertex1, int vertex2)
{
    if (vertex1 < this->numVertices && vertex2 < this->numVertices)
    {
        return this->adjMatrix[(size_t)vertex1][(size_t)vertex2];
    }
    return -1;
}

bool Graph::isSymmetric(vector<vector<int>> &matrix) // for graph being undirected it first need to be symmetric
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