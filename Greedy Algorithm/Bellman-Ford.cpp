#include <iostream>
#include <vector>
#include <climits>

struct Edge {
    int source, destination, weight;
};

void BellmanFord(const std::vector<Edge>& edges, int numVertices, int source) {
    std::vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < numVertices - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            std::cout << "Graph contains a negative-weight cycle\n";
            return;
        }
    }

    // shortest distances
    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << "\t\t" << distance[i] << "\n";
    }
}

int main() {
   
    int numVertices = 5;
    std::vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int source = 0;

    BellmanFord(edges, numVertices, source);

    return 0;
}