---
icon: circle-chevron-right
---

# bellman-ford shortest path

Slower than Dijkstra: O(V\*E) time complexity.

Handles negative edge weights (DAG), detects negative edge weight cycle.

```cpp
#include <bits/stdc++.h>
#include "graph.cpp"

using namespace std;

void bellmanford(string start, Graph graph) {
    unordered_map<string, int> distance;
    unordered_map<string, string> previous;

    // set distance to inf like Dijkstra
    for (const auto& vertex : graph.getVertices()) {
        distance[vertex.getLabel()] = INT_MAX;
    }
    distance[start] = 0;

    int V = graph.getVertices().size();

    // Edge relaxation V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& vertex : graph.getVertices()) {
            string currLabel = vertex.getLabel();

            // process neigbors
            for (const Edge& edge : graph.getEdges(Vertex(currLabel))) {
                Vertex neighbor = edge.destination;
                if (distance[currLabel] != INT_MAX) {
                    int newDist = distance[currLabel] + edge.weight;
                    if (newDist < distance[neighbor.getLabel()]) {
                        distance[neighbor.getLabel()] = newDist;
                        previous[neighbor.getLabel()] = currLabel;
                    }
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& vertex : graph.getVertices()) {
        string currLabel = vertex.getLabel();
        for (const Edge& edge : graph.getEdges(Vertex(currLabel))) {
            Vertex neighbor = edge.destination;
            if (distance[currLabel] != INT_MAX && 
                distance[currLabel] + edge.weight < distance[neighbor.getLabel()]) {
                cout << "Graph contains a negative-weight cycle" << endl;
                return;
            }
        }
    }

    cout << "Shortest paths from " << start << ":" << endl;
    for (const auto& [vertex, dist] : distance) {
        cout << vertex << " : " << (dist == INT_MAX ? "Unreachable" : to_string(dist)) << endl;
    }
}

int main() {
    Graph graph;

    // Adding vertices
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");
    graph.addVertex("E");

    // Adding edges (some with negative weights)
    graph.addEdge("A", "B", 4);
    graph.addEdge("A", "C", 2);
    graph.addEdge("B", "C", -3);
    graph.addEdge("B", "D", 2);
    graph.addEdge("C", "E", 3);
    graph.addEdge("D", "E", -1);

    // Run Bellman-Ford from vertex A
    bellmanford("A", graph);

    return 0;
}

```
