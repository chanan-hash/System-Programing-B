#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;

/**
 * By using the Graph:: and include, we;re refrencing the Graph class and the Graph.hpp file
*/

int Graph::getNumVertices()
{
    return this->numVertices;
}

vector<vector<int>> Graph::getAdjMatrix()
{
    return this->adjMatrix;
}

void Graph::loadGraph(vector<vector<int>> &matrix)
{
    if (!matrix.empty())
    {
        // Check if the matrix is square (number of rows equals number of columns)
        if (matrix.size() == matrix[0].size()) // mattrix.at(0).size() is the number of columns
        {
            // Resize the adjacency matrix to match the input matrix
            this->adjMatrix.resize(matrix.size(), vector<int>(matrix.size()));
            // Assign each value from the input matrix to the adjacency matrix
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    this->adjMatrix[i][j] = matrix[i][j];
                    // this->adjMatrix.at(i).at(j) = matrix.at(i).at(j);
                }
            }
            // Update the number of vertices
            this->numVertices = matrix.size();
        }
    }
}

void Graph::printGraph()
{
    for (int i = 0; i < this->numVertices; i++)
    {
        for (int j = 0; j < this->numVertices; j++)
        {
            std::cout << this->adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
