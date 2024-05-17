// mail - chanahelamn@gmail.com
// Author - Chanan helman

#include "Graph.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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
                // if (!this->isDirected && adjMatrix[i][j] != adjMatrix[j][i])
                // {
                //     throw invalid_argument("The graph is not directed");
                // }
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

    /**
     * The + operator overloading
     * 1. we have regular + operator that gets two graphs and return a new graph that is the sum of the two graphs
     * 2. we have += operator that gets two graphs and return the first graph after adding the second graph to it
     * 3. we have unary + operator that gets a graph and return a copy of the graph
     */

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

        // checking according to symetric the graph if it is directed or not
        if (!isSymetric(result.adjMatrix))
        {
            result.setDirected(true);
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

        if (!isSymetric(this->adjMatrix))
        {
            this->setDirected(true);
        }

        return *this;
    }

    // Unary plus operator
    Graph Graph::operator+() const
    {
        return *this; // Return a copy of the current graph
    }

    /**
     * The - operator overloading
     * 1. we have regular - operator that gets two graphs and return a new graph that is the subtraction of the two graphs
     * 2. we have -= operator that gets two graphs and return the first graph after subtracting the second graph from it
     * 3. we have unary - operator that gets a graph and return a copy of the graph with all the values negated
     */
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

        // checking according to symetric the graph if it is directed or not
        if (!isSymetric(result.adjMatrix))
        {
            result.setDirected(true);
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

        if (!isSymetric(this->adjMatrix))
        {
            this->setDirected(true);
        }

        return *this;
    }

    // Unary minus operator
    Graph Graph::operator-() const
    {
        Graph result(*this); // Create a copy of the current graph
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                result.adjMatrix[i][j] = -this->adjMatrix[i][j];
            }
        }

        if (!isSymetric(result.adjMatrix))
        {
            result.setDirected(true);
        }

        return result;
    }

    /*****Equals operator**/
    bool Graph::operator==(const Graph &other) const
    {
        // Check if the sizes of the two graphs are the same
        if (this->numVertices != other.numVertices)
        {
            return false;
        }

        // Compare the adjacency matrices
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                if (this->adjMatrix[i][j] != other.adjMatrix[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    // The != operator, the opposite of the == operator
    bool Graph::operator!=(const Graph &other) const
    {
        return !(*this == other);
    }

    /**
     * The comparison operators
     * The defenition here of graph g2 is bigger than g1:
     * 1. g1 is contained in g2
     * 2. if none of the graphs contained inside each other, then g2 is bigger than g1 if it has more edges (the places that are not 0 in the matrix)
     * 3. if they have the same number of edges if the order the matrix of g2 is biger than g1 (means the number of vertices)
     */

    bool isContained(const Graph &g1, const Graph &g2)
    {
        // Checking if g1 is contained in g2, we'll go over g1 and check if all the values are in g2
        for (size_t i = 0; i < g1.getNumVertices(); i++)
        {
            for (size_t j = 0; j < g1.getNumVertices(); j++)
            {
                if (g1.getAdjMatrix()[i][j] != 0 && g2.getAdjMatrix()[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool edgesCount(const Graph &g1, const Graph &g2)
    {
        int thisEdges = 0;
        int otherEdges = 0;
        for (size_t i = 0; i < g1.getNumVertices(); i++)
        {
            for (size_t j = 0; j < g1.getNumVertices(); j++)
            {
                if (g1.getAdjMatrix()[i][j] != 0)
                {
                    thisEdges++;
                }
                if (g2.getAdjMatrix()[i][j] != 0)
                {
                    otherEdges++;
                }
            }
        }

        if (thisEdges < otherEdges)
        {
            return true;
        }

        if (thisEdges == otherEdges) // will go according to the number of vertices
        {
            return g1.getNumVertices() < g2.getNumVertices();
        }
        return false;
    }

    bool Graph::operator<(const Graph &other) const
    {
        if (this->numVertices > other.numVertices)
        {
            // throw std::invalid_argument("g1 has more vertices than g2 check g1 > g2.");
            return false;
        }
        bool result = false;
        // Checking if g1 is contained in g2, we'll go over g1 and check if all the values are in g2
        // Check if the sizes of the two graphs are the same
        if (this->numVertices < other.numVertices)
        {
            result = isContained(*this, other);
        }
        if (!result) // means that g1 is not contained in g2, we'll check according to the number of edges
        {
            result = edgesCount(*this, other);
        }
        return result;
    }

    // The > operator, the opposite of the < operator
    bool Graph::operator>(const Graph &other) const
    {
        return other < *this;
    }

    // The <= operator
    bool Graph::operator<=(const Graph &other) const
    {
        return !(*this > other);
    }

    // The >= operator
    bool Graph::operator>=(const Graph &other) const
    {
        return !(*this < other);
    }

    /**
     * The * operator overloading
     * 1. we have the * between to graphs that defined as a matrix multiplication
     * 2. we have *= operator that gets a graph and a number and return the graph after multiplying all the values by the number
     */

    // Overloading the * operator
    Graph Graph::operator*(const Graph &other) const
    {
        // Check if the sizes of the two graphs are the same
        if (this->numVertices != other.numVertices)
        {
            throw std::invalid_argument("Graphs must be the same size to multiply them.");
        }

        Graph result(*this); // Create a copy of the current graph

        // Perform matrix multiplication
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                if (i == j)
                {
                    continue;
                }
                result.adjMatrix[i][j] = 0;
                // int sum = 0;
                for (size_t k = 0; k < this->numVertices; k++)
                {
                    // sum += this->adjMatrix[i][k] * other.adjMatrix[k][j];
                    result.adjMatrix[i][j] += this->adjMatrix[i][k] * other.adjMatrix[k][j];
                }

                // to keep the graph as a graph we will keep the 0's, because it means there no edge
                // if (sum != 0) {
                //     result.adjMatrix[i][j] = sum;
                // } else {
                //     result.adjMatrix[i][j] = 0;
                // }
            }
        }

        // checking according to symetric the graph if it is directed or not
        if (!isSymetric(result.adjMatrix))
        {
            result.setDirected(true);
        }

        return result;
    }

    // Graph * int
    Graph Graph::operator*(int num) const
    {
        Graph result(*this); // make a copy of this graph
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                result.adjMatrix[i][j] *= num;
            }
        }
        return result;
    }

    // int * Graph
    Graph operator*(int num, const Graph &g)
    {
        return g * num; // use the Graph * int operator
    }

    // Multiply a graph by a scalar
    Graph &Graph::operator*=(const int &num)
    {
        // Multiply all the values in the adjacency matrix by the number
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                this->adjMatrix[i][j] *= num;
            }
        }

        return *this;
    }

    // Dividing a graph by a scalar
    Graph &Graph::operator/=(const int &num)
    {
        if (num == 0) // Check if the number is zero
        {
            throw std::invalid_argument("Cannot divide by zero");
        }

        // Divide all the values in the adjacency matrix by the number
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                this->adjMatrix[i][j] /= num;
            }
        }
        return *this;
    }

    /*****Increment and decremet operators (prefix and postfix)******/

    // Prefix increment operator
    Graph &Graph::operator++()
    {
        // Increment all the values in the adjacency matrix by 1
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                if (this->adjMatrix[i][j] != 0)
                {
                    this->adjMatrix[i][j]++;
                }
            }
        }

        if (!isSymetric(this->adjMatrix))
        {
            this->setDirected(true);
        }

        return *this;
    }

    // postfix increment operator, the compiler will see that the int is a dummy parameter and will know that this is the postfix version
    Graph Graph::operator++(int)
    {
        Graph temp(*this); // make a copy for result
        ++(*this);         // Use the prefix version to increment this instance
        return temp;       // return the copy (the old) value.
    }

    // Prefix decrement operator
    Graph &Graph::operator--()
    {
        // Decrement all the values in the adjacency matrix by 1
        for (size_t i = 0; i < this->numVertices; i++)
        {
            for (size_t j = 0; j < this->numVertices; j++)
            {
                if (this->adjMatrix[i][j] != 0)
                {
                    this->adjMatrix[i][j]--;
                }
            }
        }

        if (!isSymetric(this->adjMatrix))
        {
            this->setDirected(true);
        }

        return *this;
    }

    // postfix decrement operator
    Graph Graph::operator--(int)
    {
        Graph temp(*this); // make a copy for result
        --(*this);         // Use the prefix version to decrement this instance
        return temp;       // return the copy (the old) value.
    }

    /**
     * The << operator overloading
     * 1. we have << operator that gets a graph and return a reference to the ostream object
     * 2. we have a friend function that gets a graph and return a reference to the ostream object
     */

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
} // namespace ariel