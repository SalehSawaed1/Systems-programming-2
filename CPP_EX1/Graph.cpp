// E-mail : salehsawaed16@gmail.com

#include "Graph.hpp"
#include <stdexcept>
#include <iostream>

namespace ariel {

    // Constructor
    Graph::Graph(const std::vector<std::vector<int>>& matrix) : adjacencyMatrix(matrix) {
        vertices = matrix.size();
        edges = calculateEdges();
        isDirected = false;
    }

    // Method to load a graph from a 2D vector (adjacency matrix)
    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix.size() != matrix[0].size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        for (const auto& row : matrix) {
            if (row.size() != matrix.size()) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }

        vertices = matrix.size();
        edges = 0;

        for (const auto& row : matrix) {
            for (int value : row) {
                if (value != 0) {
                    edges++;
                }
            }
        }

        adjacencyMatrix = matrix;
        this->isDirected = false;
    }

    // Method to print basic information about the graph
    void Graph::printGraph() const {
        std::cout << "Graph with " << vertices << " vertices and " << edges << " edges." << std::endl;
    }

    // Method to get the adjacency matrix of the graph
    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    // Method to calculate the number of edges in the graph
    int Graph::calculateEdges() const {
        int count = 0;

        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = i; j < adjacencyMatrix[i].size(); ++j) { // Adjusted: Count edges correctly
                if (adjacencyMatrix[i][j] != 0) {
                    count++;
                }
            }
        }
        return count;
    }

    // Scalar multiplication operator (in-place)
    Graph& Graph::operator*=(int scalar) {
        for (auto& row : adjacencyMatrix) {
            for (auto& value : row) {
                value *= scalar;
            }
        }
        return *this;
    }

    // Scalar multiplication operator (returns a new graph)
    Graph Graph::operator*(int scalar) const {
        Graph result = *this;
        result *= scalar;
        return result;
    }

    // Addition operator for graphs
    Graph Graph::operator+(const Graph& other) const {
        if (vertices != other.vertices) {
            throw std::invalid_argument("Graphs must have the same number of vertices for addition.");
        }

        Graph result = *this;

        for (size_t i = 0; i < vertices; ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                result.adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }

        result.edges = result.calculateEdges();
        return result;
    }

    // In-place addition operator for graphs
    Graph& Graph::operator+=(const Graph& other) {
        *this = *this + other;
        return *this;
    }

    // Subtraction operator for graphs
    Graph Graph::operator-(const Graph& other) const {
        if (vertices != other.vertices) {
            throw std::invalid_argument("Graphs must have the same number of vertices for subtraction.");
        }

        Graph result = *this;

        for (size_t i = 0; i < vertices; ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                result.adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }

        result.edges = result.calculateEdges();
        return result;
    }

    // In-place subtraction operator for graphs
    Graph& Graph::operator-=(const Graph& other) {
        *this = *this - other;
        return *this;
    }

    // Matrix multiplication operator for graphs
    Graph Graph::operator*(const Graph& other) const {
        // Ensure the matrices can be multiplied
        if (adjacencyMatrix[0].size() != other.getAdjacencyMatrix().size()) {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        size_t n = adjacencyMatrix.size();
        size_t p = other.getAdjacencyMatrix()[0].size();

        std::vector<std::vector<int>> resultMatrix(n, std::vector<int>(p, 0));

        // Perform matrix multiplication
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < p; ++j) {
                for (size_t k = 0; k < adjacencyMatrix[0].size(); ++k) {
                    resultMatrix[i][j] += adjacencyMatrix[i][k] * other.getAdjacencyMatrix()[k][j];
                }
            }
        }

        // Ensure the main diagonal remains 0
        for (size_t i = 0; i < n; ++i) {
            resultMatrix[i][i] = 0;
        }

        return Graph(resultMatrix);
    }

    // In-place matrix multiplication operator for graphs
    Graph& Graph::operator*=(const Graph& other) {
        *this = *this * other;  // Delegate to the multiplication operator
        return *this;
    }

    // Equality operator for graphs
    bool Graph::operator==(const Graph& other) const {
        return vertices == other.vertices &&
               edges == other.edges &&
               adjacencyMatrix == other.adjacencyMatrix &&
               isDirected == other.isDirected;
    }

    // Inequality operator for graphs
    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

    // Greater-than operator for graphs (compares by vertices and edges)
    bool Graph::operator>(const Graph& other) const {
        return vertices > other.vertices ||
               (vertices == other.vertices && edges > other.edges);
    }

    // Less-than operator for graphs (compares by vertices and edges)
    bool Graph::operator<(const Graph& other) const {
        return vertices < other.vertices ||
               (vertices == other.vertices && edges < other.edges);
    }

    // Greater-than-or-equal-to operator for graphs
    bool Graph::operator>=(const Graph& other) const {
        return !(*this < other);
    }

    // Less-than-or-equal-to operator for graphs
    bool Graph::operator<=(const Graph& other) const {
        return !(*this > other);
    }

    // Prefix increment operator (increases each element of the adjacency matrix)
    Graph& Graph::operator++() {
        for (auto& row : adjacencyMatrix) {
            for (auto& value : row) {
                ++value;
            }
        }
        return *this;
    }

    // Postfix increment operator (increases each element of the adjacency matrix)
    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix decrement operator (decreases each element of the adjacency matrix)
    Graph& Graph::operator--() {
        for (auto& row : adjacencyMatrix) {
            for (auto& value : row) {
                --value;
            }
        }
        return *this;
    }

    // Postfix decrement operator (decreases each element of the adjacency matrix)
    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    // Unary plus operator (returns the graph as-is)
    Graph& Graph::operator+() {
        return *this;
    }

    // Unary minus operator (negates each element of the adjacency matrix)
    Graph& Graph::operator-() {
        for (auto& row : adjacencyMatrix) {
            for (auto& value : row) {
                value = -value;
            }
        }
        return *this;
    }

    // Division operator for graphs (divides each element of the adjacency matrix by a scalar)
    Graph Graph::operator/(int scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }

        Graph result = *this;
        for (auto& row : result.adjacencyMatrix) {
            for (auto& value : row) {
                value /= scalar;
            }
        }
        return result;
    }

    // In-place division operator for graphs (divides each element by a scalar)
    Graph& Graph::operator/=(int scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }

        for (auto& row : adjacencyMatrix) {
            for (auto& value : row) {
                value /= scalar;
            }
        }
        return *this;
    }

    // Stream output operator (prints the adjacency matrix)
    std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        const auto& matrix = graph.getAdjacencyMatrix();
        for (const auto& row : matrix) {
            os << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                os << row[i];
                if (i < row.size() - 1) os << ", ";
            }
            os << "]" << std::endl;
        }
        return os;
    }
}
