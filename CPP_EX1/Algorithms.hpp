#include <string>
#include "Graph.hpp"
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

namespace ariel {
    class Algorithms {
    public:
        // Constructor
        Algorithms() = default;

        // Destructor
        ~Algorithms() = default;

        // Checks if the graph is connected (all vertices are reachable from any vertex)
        static bool isConnected(const Graph& g);

        // Finds the shortest path between two vertices and returns a string representation of the path
        static std::string shortestPath(const Graph& g, int start, int end);

        // Checks whether there is a cycle in the graph, prints the cycle if it exists, and returns true; otherwise returns false
        static bool isContainsCycle(const Graph& g);

        // Checks whether the graph is bipartite, returning a string representation of the partition if possible
        static std::string isBipartite(const Graph& g);


    };
}
#endif // ALGORITHMS_HPP