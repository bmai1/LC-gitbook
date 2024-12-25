---
icon: face-smile-beam
---

# tree diameter

The diameter of the tree is the longest path between two nodes in a tree.

From [https://codeforces.com/blog/entry/101271](https://codeforces.com/blog/entry/101271), find diameter using two-pass dfs:

* Run DFS from any node P which maximizes distance to node A
* Run DFS from node A which maximizes distance to node B. This is the diameter
* O(N), where N is number of nodes in the tree

Note: A tree as an adjacency list is just a special graph.

* Connected: There is exactly one path between any two nodes
* Acyclic: It contains no cycles
* N-1 Edges: A tree with N nodes always has N−1 edges

```cpp
pair<int, int> dfs(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size());
    stack<pair<int, int>> stk;
    stk.push({start, 0});
    int farthest_node = start, max_dist = 0;

    while (!stk.empty()) {
        auto [node, dist] = stk.top(); stk.pop();
        if (dist > max_dist) {
            farthest_node = node;
            max_dist = dist;
        }
        visited[node] = true;
        for (int next : adj[node]) {
            if (!visited[next]) {
                stk.push({next, dist + 1});
            }
        }
    }

    return {farthest_node, max_dist};
}
```

```cpp
int diameter(const vector<vector<int>>& adj) {
    auto [a, _]        = dfs(0, adj); // Find node A
    auto [b, diameter] = dfs(a, adj); // Find node B and the diameter
    return diameter;
}
```
