---
icon: user-xmark
---

# bfs/dfs for graphs

```cpp
#include <bits/stdc++.h>

using namespace std; 

void bfs(int start, vector<vector<int>>& adj) {
    queue<int> q;
    vector<bool> visited(adj.size());

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    cout << endl;
}

void dfs(int start, vector<vector<int>>& adj) {
    stack<int> stk;
    vector<bool> visited(adj.size());

    stk.push(start);

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        
        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
            for (int neighbor : adj[node]) {
                // otherwise undirected graphs will visit edges twice
                if (!visited[neighbor]) {
                    stk.push(neighbor);
                }
            }
        }
    }

    cout << endl;
}


int main() {
    // given edges between vertices
    vector<vector<int>> edges;

    edges.push_back({0, 1});
    edges.push_back({0, 2});
    edges.push_back({0, 3});
    edges.push_back({1, 4});
    edges.push_back({1, 5});
    edges.push_back({2, 6});
    edges.push_back({3, 7});

    // construct adjacency list
    int n = edges.size();
    vector<vector<int>> adj = vector<vector<int>>(n + 1);
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // test graph traversal algorithms
    bfs(0, adj);
    dfs(0, adj);
}
```
