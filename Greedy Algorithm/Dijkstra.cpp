#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> Dijkstra(const Graph& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    return dist;
}

int main() {
    cout<<"enter the number of nodes and edges";
    int n, m; 
    cin >> n >> m;
    
    Graph graph(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cout<< "enter edge details(source,dest,weight)";
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }
    
    int source;
    cout<<"enter the source node index";
    cin >> source;
    
    vector<int> dist = Dijkstra(graph, source);
    
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
    
    return 0;
}