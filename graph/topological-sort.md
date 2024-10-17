# 🍇 topological sort

For Directed Acyclic Graphs (DAG)&#x20;

* linear ordering of vertices so that for every edge (u, v), u comes before v (is satisfied)
* can use dfs and bfs to find a valid path (or detect a cycle, in which case the sort is invalid)
* may take in a graph input as an adjacency list

Example problem (Kattis pickupsticks):

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;  
vector<int> visited;         
vector<int> ans;      
bool hasCycle = false;      

void dfs(int node) {
    visited[node] = 1;  
    for (int neighbor : adj[node]) {
        if (visited[neighbor] == 0) dfs(neighbor);
        // topological sort fails for cycle
        else if (visited[neighbor] == 1) {
            hasCycle = true;
            return;
        }
    }
    visited[node] = 2;   
    ans.push_back(node);
}

void topologicalSort(int n) {
    visited.assign(n + 1, 0); 

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
}

int main() {
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;  
    cin >> n >> m;
    
    adj.resize(n + 1); 
    
    // form adjacency list from input
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
    }

    topologicalSort(n);
    
    if (!hasCycle) {
        for (int i = n - 1; i >= 0; --i) {
            cout << ans[i] << endl;
        }
    }
    else cout << "IMPOSSIBLE" << endl;
}
```
