class Solution {
public:
bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    if (visited[node]) return false; // cycle detected
    visited[node] = true;
    
    for (int nei : adj[node]) {
        if (nei == parent) continue; // skip edge back to parent
        if (!dfs(nei, node, adj, visited)) return false;
    }
    return true;
}

bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false; // must have n-1 edges
    
    // Build adjacency list
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    vector<bool> visited(n, false);
    if (!dfs(0, -1, adj, visited)) return false; // cycle check
    
    // check connectivity
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}
};
