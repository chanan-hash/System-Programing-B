// mail - chanahelamn@gmail.com
// Author - Chanan helman

#include <iostream>
#include <vector>
#include "Graph.hpp"
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;
// using namespace ariel;
/**
 * By using the Graph:: and include, we're refrencing the Graph class and the Graph.hpp file
 */
namespace ariel
{
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

    /***************************  Operator overloading     *************************/

    // Overloading the + operator
    Graph Graph::operator+(const Graph &other)
    {
        // Checking the number of vertices in both graphs are the same
        if (this->numVertices != other.numVertices)
        {
            throw invalid_argument("The number of vertices in both graphs must be the same");
        }

        Graph result; // Create a new graph object to store the result
        // Assuming numVertices, adjMatrix are accessible members of Graph

        result.numVertices = this->numVertices; // it suppose to be the same size

        // Adding the two adjacency matrices
        for (size_t i = 0; i < this->numVertices; i++)
        {
            vector<int> row;
            for (size_t j = 0; j < this->numVertices; j++)
            {
                row.push_back(this->adjMatrix[i][j] + other.adjMatrix[i][j]);
            }
            result.adjMatrix.push_back(row);
        }

        return result;
    }

    Graph &Graph::operator+=(const Graph &other)
    {
        // Check if the sizes of the two graphs are the same
        if (this->numVertices != other.numVertices)
        {
            throw std::invalid_argument("Graphs must be the same size to add them together.");
        }

        // Add the adjacency matrices
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                this->adjMatrix[i][j] += other.adjMatrix[i][j];
            }
        }

        // Returning a reference to the current object. This is not a pointer
        // Returning *this from an operator overload function allows you to chain operations together
        // In the context of the operator+= function, return *this; is returning a reference to the current Graph object after it has been modified by the addition operation.

        return *this;
    }


    // Overloading the - operator
    Graph Graph::operator-(const Graph &other)
    {
        // Checking the number of vertices in both graphs are the same
        if (this->numVertices != other.numVertices)
        {
            throw invalid_argument("The number of vertices in both graphs must be the same");
        }

        Graph result; // Create a new graph object to store the result
        // Assuming numVertices, adjMatrix are accessible members of Graph

        result.numVertices = this->numVertices; // it suppose to be the same size

        // Subtracting the two adjacency matrices
        for (size_t i = 0; i < this->numVertices; i++)
        {
            vector<int> row;
            for (size_t j = 0; j < this->numVertices; j++)
            {
                row.push_back(this->adjMatrix[i][j] - other.adjMatrix[i][j]);
            }
            result.adjMatrix.push_back(row);
        }

        return result;
    }

    Graph &Graph::operator-=(const Graph &other)
    {
        // Check if the sizes of the two graphs are the same
        if (this->numVertices != other.numVertices)
        {
            throw std::invalid_argument("Graphs must be the same size to subtract them.");
        }

        // Subtract the adjacency matrices
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                this->adjMatrix[i][j] -= other.adjMatrix[i][j];
            }
        }

        // Returning a reference to the current object. This is not a pointer
        // Returning *this from an operator overload function allows you to chain operations together
        // In the context of the operator+= function, return *this; is returning a reference to the current Graph object after it has been modified by the addition operation.

        return *this;
    }


    // Replace the << operator with the following function
    std::ostream &operator<<(std::ostream &os, const Graph &g)
    {
        for (size_t i = 0; i < g.getNumVertices(); i++)
        {
            os << "[";
            for (size_t j = 0; j < g.getNumVertices(); j++)
            {
                os << g.getAdjMatrix()[i][j];
                if (j != g.getNumVertices() - 1)
                {
                    os << ", ";
                }
            }
            os << "]";
            if (i != g.getNumVertices() - 1)
            {
                os << ", ";
            }
            os << std::endl;
        }
        os << std::endl;
        return os;
    }
}