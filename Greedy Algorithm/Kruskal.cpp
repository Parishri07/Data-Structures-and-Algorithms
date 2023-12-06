#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Data structure to represent a disjoint set
struct DisjointSet {
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find the root of a given vertex
    int find(int v) {
        if (v != parent[v])
            parent[v] = find(parent[v]);
        return parent[v];
    }

    // Union of two sets
    void Union(int u, int v) {
        u = find(u);
        v = find(v);
        parent[u] = v;
    }
};

// Comparator function to sort edges based on their weight
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Kruskal's algorithm to find the Minimum Spanning Tree
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    // Sort edges in ascending order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> mst;
    DisjointSet ds(V);

    for (const Edge& edge : edges) {
        int src = edge.src;
        int dest = edge.dest;

        int srcRoot = ds.find(src);
        int destRoot = ds.find(dest);

        // If including this edge does not form a cycle, add it to the MST
        if (srcRoot != destRoot) {
            mst.push_back(edge);
            ds.Union(srcRoot, destRoot);
        }
    }

    return mst;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    vector<Edge> mst = kruskalMST(edges, V);

    cout << "Minimum Spanning Tree:\n";
    for (const Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}