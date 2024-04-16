#include <iostream>>
#include <vector>

using namespace std;
class Graph
{
private:
    vector<vector<int>> adjMatrix;
    int numVertices;

public:
    void loadGraph(vector<vector<int>> &matrix)
    {
        if (!matrix.empty())
        {
            // Check if the matrix is square (number of rows equals number of columns)
            if (matrix.size() == matrix[0].size())
            {
                // Resize the adjacency matrix to match the input matrix
                adjMatrix.resize(matrix.size(), vector<int>(matrix.size()));
                // Assign each value from the input matrix to the adjacency matrix
                for (int i = 0; i < matrix.size(); i++)
                {
                    for (int j = 0; j < matrix[i].size(); j++)
                    {
                        adjMatrix[i][j] = matrix[i][j];
                    }
                }
                // Update the number of vertices
                numVertices = matrix.size();
            }
        }
    }

    void printGraph()
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
    
};
