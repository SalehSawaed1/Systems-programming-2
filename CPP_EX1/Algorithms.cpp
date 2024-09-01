// E-mail : salehsawaed16@gmail.com

#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

namespace ariel {

    // Function to check if the graph is connected
    bool Algorithms::isConnected(const Graph& g) {
        size_t numVertices = g.getVertices();
        std::vector<bool> visited(numVertices, false);

        std::queue<size_t> vertexQueue;
        vertexQueue.push(0);
        visited[0] = true;

        while (!vertexQueue.empty()) {
            size_t currentVertex = vertexQueue.front();
            vertexQueue.pop();
            for (size_t neighbor = 0; neighbor < numVertices; ++neighbor) {
                if (g.getAdjacencyMatrix()[currentVertex][neighbor] && !visited[neighbor]) {
                    vertexQueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }

    // Function to find the shortest path between two vertices
    std::string Algorithms::shortestPath(const Graph& g, int start, int end) {
        size_t numVertices = g.getVertices();
        std::queue<int> vertexQueue;
        vertexQueue.push(start);
        std::vector<int> predecessor(numVertices, -1);
        std::vector<bool> visited(numVertices, false);
        visited[start] = true;

        while (!vertexQueue.empty()) {
            int currentVertex = vertexQueue.front();
            vertexQueue.pop();

            if (currentVertex == end) {
                std::string path = std::to_string(end);
                while (predecessor[currentVertex] != -1) {
                    currentVertex = predecessor[currentVertex];
                    path = std::to_string(currentVertex) + "->" + path;
                }
                return path;
            }

            for (size_t neighbor = 0; neighbor < numVertices; ++neighbor) {
                if (g.getAdjacencyMatrix()[currentVertex][neighbor] && !visited[neighbor]) {
                    vertexQueue.push(neighbor);
                    visited[neighbor] = true;
                    predecessor[neighbor] = currentVertex;
                }
            }
        }

        return "-1";
    }

    // Function to detect a cycle in the graph and print it
    bool Algorithms::isContainsCycle(const Graph& g) {
        size_t numVertices = g.getVertices();
        std::vector<bool> visited(numVertices, false);
        std::vector<int> parent(numVertices, -1);

        for (size_t vertex = 0; vertex < numVertices; ++vertex) {
            if (!visited[vertex]) {
                std::stack<int> vertexStack;
                vertexStack.push(vertex);

                while (!vertexStack.empty()) {
                    int currentVertex = vertexStack.top();
                    vertexStack.pop();

                    if (!visited[currentVertex]) {
                        visited[currentVertex] = true;

                        for (size_t neighbor = 0; neighbor < numVertices; ++neighbor) {
                            if (g.getAdjacencyMatrix()[currentVertex][neighbor]) {
                                if (!visited[neighbor]) {
                                    vertexStack.push(neighbor);
                                    parent[neighbor] = currentVertex;
                                } else if (parent[currentVertex] != neighbor) {
                                    std::vector<int> cycleVertices;
                                    int currentCycleVertex = currentVertex;
                                    cycleVertices.push_back(neighbor);

                                    while (currentCycleVertex != neighbor) {
                                        cycleVertices.push_back(currentCycleVertex);
                                        currentCycleVertex = parent[currentCycleVertex];
                                    }
                                    cycleVertices.push_back(neighbor);

                                    std::cout << "The cycle is: ";
                                    for (size_t i = 0; i < cycleVertices.size(); ++i) {
                                        std::cout << cycleVertices[i];
                                        if (i != cycleVertices.size() - 1) std::cout << "->";
                                    }
                                    std::cout << std::endl;

                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    // Function to check if the graph is bipartite and return the partitions
    std::string Algorithms::isBipartite(const Graph& g) {
        size_t vertexCount = g.getVertices();
        std::vector<int> vertexColors(vertexCount, -1);
        std::vector<int> partitionA, partitionB;

        for (size_t startVertex = 0; startVertex < vertexCount; ++startVertex) {
            if (vertexColors[startVertex] == -1) {
                vertexColors[startVertex] = 0;
                partitionA.push_back(startVertex);
                std::queue<int> vertexQueue;
                vertexQueue.push(startVertex);

                while (!vertexQueue.empty()) {
                    int currentVertex = vertexQueue.front();
                    vertexQueue.pop();

                    for (size_t neighbor = 0; neighbor < vertexCount; ++neighbor) {
                        if (g.getAdjacencyMatrix()[currentVertex][neighbor]) {
                            if (vertexColors[neighbor] == -1) {
                                vertexColors[neighbor] = 1 - vertexColors[currentVertex];
                                if (vertexColors[neighbor] == 0) {
                                    partitionA.push_back(neighbor);
                                } else {
                                    partitionB.push_back(neighbor);
                                }
                                vertexQueue.push(neighbor);
                            } else if (vertexColors[neighbor] == vertexColors[currentVertex]) {
                                return "0";
                            }
                        }
                    }
                }
            }
        }

        std::string result = "The graph is bipartite: A={";
        for (size_t i = 0; i < partitionA.size(); ++i) {
            result += std::to_string(partitionA[i]);
            if (i < partitionA.size() - 1) {
                result += ", ";
            }
        }
        result += "}, B={";
        for (size_t i = 0; i < partitionB.size(); ++i) {
            result += std::to_string(partitionB[i]);
            if (i < partitionB.size() - 1) {
                result += ", ";
            }
        }
        result += "}";

        return result;
    }
}
