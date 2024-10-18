# 🤩 graph representations

### Common Graph Representations

Adjacency list:

* each vertex stores a list of edges
* O(V + E) space, each vertex appears 1x while edge 2x

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

Adjacency matrix -> each value adj\[a]\[b] indicate edge from node a to node b (correspond to weight)

<figure><img src="../.gitbook/assets/adj matrix (1).png" alt=""><figcaption><p>graphical rep. of adj. matrix</p></figcaption></figure>

* edge list -> don't need to start from particular node, each pair (a, b) denote edge a->b

```cpp
vector<pair<int, int>> edges;
vector<tuple<int, int, int>> edges; // weighted
```
