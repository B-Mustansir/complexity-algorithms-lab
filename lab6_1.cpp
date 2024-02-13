#include <iostream>
#include <vector>
using namespace std;

#define INF 99999

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(graph); // Copy the graph to store the shortest distances

    // Applying the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Outputting the shortest distances
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, INF)); // Initialize graph with INF distance

    // Input the edges and weights
    cout << "Enter the edges and their weights (source, destination, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // Setting diagonal elements to 0
    for (int i = 0; i < V; i++) {
        graph[i][i] = 0;
    }

    floydWarshall(graph, V);

    return 0;
}
