#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsRecursive(vector<vector<int>>& graph, int start, vector<bool>& visited) {

    visited[start] = true;
    cout << start << " ";

    for (int neighbor : graph[start]) {
        if (!visited[neighbor]) {
            dfsRecursive(graph, neighbor, visited);
        }
    }
}

void dfsIterative(vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);

    stack<int> stack;

    stack.push(start);

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            visited[vertex] = true;
            cout << vertex << " ";

            for (int neighbor : graph[vertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices);

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);

        graph[v].push_back(u);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "DFS Recursive:" << endl;
    vector<bool> visitedRecursive(numVertices, false);
    dfsRecursive(graph, 0, visitedRecursive);
    cout << endl;

    cout << "\nDFS Iterative:" << endl;
    dfsIterative(graph, 0);
    cout << endl;

    return 0;
}
