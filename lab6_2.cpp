#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999

int tsp(vector<vector<int>>& graph, int start, int mask, vector<vector<int>>& dp) {
    int n = graph.size();
    
    // If all cities have been visited
    if (mask == (1 << n) - 1) {
        return graph[start][0]; // Return to the starting city
    }
    
    // If already computed
    if (dp[start][mask] != -1) {
        return dp[start][mask];
    }
    
    int ans = INF;
    
    // Try to visit all cities
    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) { // If city 'next' is not visited
            int newMask = mask | (1 << next);
            ans = min(ans, graph[start][next] + tsp(graph, next, newMask, dp));
        }
    }
    
    return dp[start][mask] = ans;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    // Starting from city 0
    int start = 0;
    int mask = 1 << start; // Initially, only the start city is visited

    int minCost = tsp(graph, start, mask, dp);

    cout << "Minimum cost for the TSP: " << minCost << endl;

    return 0;
}
