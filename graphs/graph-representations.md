# 🤩 graph representations

### Common Graph Representations

* adjacency list (size n vertices)

```cpp
vector<vector<int>> adj(n); // n-vertices
vector<vector<pair<int, int>>> adj(n); // weighted 
```

for example, if node a has edge to node b, adj\[a].push\_back(b);

if weighted, adj\[a].push\_back({b, weight});

```cpp
for (int currNode = 0; currNode < adj.size(); ++currNode) {
    for (auto neighbor : adj[currNode]) {
        // visit all possible nodes from currNode
        // process neighbor
    }
}
```

* adjacency matrix -> each value adj\[a]\[b] indicate edge from node a to node b (correspond to weight)
* edge list -> don't need to start from particular node, each pair (a, b) denote edge a->b

```cpp
vector<pair<int, int>> edges;
vector<tuple<int, int, int>> edges; // weighted
```
