---
icon: person-carry-box
---

# dijkstra shortest path

Time complexity: O(V^2) with array, O(V + ElogV) with min-priority queue (heap)

Note: because Dijkstra's greedily selects the min edge weight, it cannot handle negative weights (negative weight cycle).

Basic implementation of graph:

```cpp
#include <bits/stdc++.h>

using namespace std;

class Vertex {
    public:
        Vertex(string label) : label(label) {}

        string getLabel() const {
            return label;
        }

        bool operator==(const Vertex& other) const {
            return label == other.label;
        }
    
        // Hash function to use Vertex in unordered_map
        struct HashFunction {
        size_t operator()(const Vertex& v) const {
            return hash<string>()(v.getLabel());
        }
    };
    private: 
        string label;
};

class Edge {
    public:
        Vertex source;
        Vertex destination;
        double weight;

        // initializer list ctor
        Edge(Vertex source, Vertex destination, double weight); 
};

// can declare outside of class
Edge::Edge(Vertex source, Vertex destination, double weight) : source(source), destination(destination), weight(weight) {}

// simpler representation of edges for integer vertices
// [source, destination, weight] vectors
// vector<vector<int>> edges;

class Graph {
    public:
        Graph(const vector<Edge>& edges) {
            for (const Edge& edge : edges) {
                addEdge(edge.source, edge.destination, edge.weight);
            }
        }
        Vertex addVertex(string label) {
            Vertex newVertex = Vertex(label);
            adjacencyList[newVertex];
            return newVertex;
        }
        void addEdge(const Vertex& source, const Vertex& destination, double weight) {
            Edge edge(source, destination, weight);
            adjacencyList[source].push_back(edge);
            adjacencyList[destination].push_back(edge); // For undirected graphs, add both directions
        }

        vector<Vertex> getVertices() const {
            vector<Vertex> vertices;
            for (const auto& pair : adjacencyList) {
                vertices.push_back(pair.first);
            }
            return vertices;
        }

        const vector<Edge>& getEdges(const Vertex& vertex) const {
            auto it = adjacencyList.find(vertex);
            if (it != adjacencyList.end()) {
                return it->second;
            }
            throw runtime_error("Vertex not found in the graph.");
        }

    private:
        unordered_map<Vertex, vector<Edge>, Vertex::HashFunction> adjacencyList;
};
```

Applying Dijkstra's:

```cpp
#include <bits/stdc++.h>
#include "graph.cpp"

using namespace std;

void dijkstra(string start, Graph graph) {
    unordered_map<string, int> distance;
    unordered_map<string, string> previous; // track shortest path tree

    for (const auto& vertex : graph.getVertices()) {
        // set vertex distances to inf.
        distance[vertex.getLabel()] = INT_MAX;
    }
    distance[start] = 0;

    // store vertices by distance with min-heap
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [dist, currLabel] = pq.top();
        pq.pop();

        if (dist > distance[currLabel]) continue;

        // process neighbors
        for (const Edge& edge : graph.getEdges(Vertex(currLabel))) {
            Vertex neighbor = edge.destination;
            int weight = edge.weight;
            int newDist = dist + weight;

            // update if lower dist
            if (newDist < distance[neighbor.getLabel()]) {
                distance[neighbor.getLabel()] = newDist;
                previous[neighbor.getLabel()] = currLabel;
                pq.push({newDist, neighbor.getLabel()});
            }
        }
    }

    cout << "Shortest paths from " << start << ":" << endl;
    for (const auto& [vertex, dist] : distance) {
        cout << vertex << " : " << (dist == INT_MAX ? "Unreachable" : to_string(dist)) << endl;
    }
}

int main() {
    // Sample edges for the graph (with weights)
    vector<Edge> edges = {
        Edge(Vertex("0"), Vertex("1"), 4),
        Edge(Vertex("0"), Vertex("2"), 2),
        Edge(Vertex("1"), Vertex("3"), 5),
        Edge(Vertex("2"), Vertex("3"), 1),
        Edge(Vertex("3"), Vertex("4"), 3)
    };

    Graph graph(edges);

    dijkstra("0", graph);

    return 0;
}
```
