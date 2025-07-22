#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, int path_sum, vector<int>& all_sums, const vector<int>& A) {
    visited[u] = true;
    path_sum += A[u];
    all_sums.push_back(path_sum);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, path_sum, all_sums, A);
        }
    }

    visited[u] = false;
}

int max_diff(const vector<vector<int>>& edges, const vector<int>& A) {
    int n = A.size();
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int result = 0;
    for (int start = 0; start < n; ++start) {
        vector<bool> visited(n, false);
        vector<int> all_sums;
        dfs(start, adj, visited, 0, all_sums, A);
        if (!all_sums.empty()) {
            int max_sum = *max_element(all_sums.begin(), all_sums.end());
            int min_sum = *min_element(all_sums.begin(), all_sums.end());
            result = max(result, max_sum - min_sum);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}, {2, 3}};
    vector<int> A = {5, 7, 4, 3, 6};
    cout << "Chênh lệch độ khó lớn nhất là: " << max_diff(edges, A) << endl;
    return 0;
}
