# 🍇 topological sort

For Directed Acyclic Graphs (DAG)&#x20;

* linear ordering of vertices so that for every edge (u, v), u comes before v (is satisfied)
* can use dfs and bfs to find a valid path (or detect a cycle, in which case the sort is invalid)
* may take in a graph input as an adjacency list

Kahn's Algorithm (BFS-based):

* "In-degree" refers to the number of edges that are directed towards a specific vertex
* Find vertices with no in-degrees and remove them from graph
* Update remaining vertices' incoming edges
* Repeat until all vertices are sorted

```cpp
#include <bits/stdc++.h>
#include "graph.cpp"

using namespace std;

vector<Vertex> topologicalSort(Graph graph) {
    vector<Vertex> res;
    vector<Vertex> vertices = graph.getVertices();

    unordered_map<string, int> inDegree;
    for (const Vertex& vertex : vertices) {
        inDegree[vertex.getLabel()] = 0;
    }

    for (const Vertex& vertex : vertices) {
        for (const Edge& edge : graph.getEdges(vertex)) {
            inDegree[edge.destination.getLabel()]++;
        }
    }

    queue<Vertex> q;
    for (const Vertex& vertex : vertices) {
        if (inDegree[vertex.getLabel()] == 0) {
            q.push(vertex);
        }
    }

    while (!q.empty()) {
        Vertex curr = q.front();
        q.pop();
        res.push_back(curr);

        // Sort edges based on destination vertex label before processing
        vector<Edge> edges = graph.getEdges(curr);
        sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
            return e1.destination.getLabel() < e2.destination.getLabel();
        });

        for (const Edge& edge : edges) {
            string neighborLabel = edge.destination.getLabel();
            inDegree[neighborLabel]--;
            if (inDegree[neighborLabel] == 0) {
                q.push(edge.destination);
            }
        }
    }

    return res;
}

int main() {
    Graph graph;

    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");
    graph.addVertex("E");

    graph.addEdge("A", "B", 0);
    graph.addEdge("A", "C", 0);
    graph.addEdge("B", "C", 0);
    graph.addEdge("B", "D", 0);
    graph.addEdge("C", "E", 0);
    graph.addEdge("D", "E", 0);

    vector<Vertex> sortedVertices = topologicalSort(graph);
    for (const Vertex& vertex : sortedVertices) {
        cout << vertex.getLabel() << " ";
    }
    cout << endl;

    return 0;
}
```

DFS can also be used.

Example DFS-based topological sorting problem (Kattis pickupsticks):

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
    // finished processing node with no cycle
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
