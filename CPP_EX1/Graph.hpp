#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

namespace ariel {

    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        int vertices;
        int edges;
        bool isDirected;
        int calculateEdges() const;

    public:
        // Constructors
        Graph() : vertices(0), edges(0), isDirected(false) {}
        Graph(const std::vector<std::vector<int>>& matrix);

        // Getters
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

        // Load and print graph
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;

        // Accessors for vertices and edges
        int getEdges() const { return this->edges; }
        int getVertices() const { return this->vertices; }

        // Comparison operators
        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other) const;
        bool operator>(const Graph &other) const;
        bool operator<(const Graph &other) const;
        bool operator>=(const Graph &other) const;
        bool operator<=(const Graph &other) const;

        // Arithmetic operators
        Graph& operator*=(int scalar);
        Graph operator*(int scalar) const;
        Graph operator+(const Graph &other) const;
        Graph& operator+=(const Graph &other);
        Graph& operator-=(const Graph &other);
        Graph operator-(const Graph &other) const;
        Graph operator*(const Graph &other) const; // Matrix multiplication with another graph
        Graph& operator*=(const Graph &other);     // Matrix multiplication assignment

        // Increment and decrement operators
        Graph& operator++();        // Prefix increment
        Graph operator++(int);      // Postfix increment
        Graph& operator--();        // Prefix decrement
        Graph operator--(int);      // Postfix decrement

        // Unary operators
        Graph& operator+();         // Unary plus
        Graph& operator-();         // Unary minus

        // Division operators
        Graph operator/(int scalar) const;         // Divide by scalar
        Graph& operator/=(int scalar);             // Divide by scalar

        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
    };

}

#endif // GRAPH_HPP
