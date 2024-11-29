---
description: Basically graph bfs using dp and deque instead of min-heap priority queue
icon: tire-pressure-warning
---

# 0-1 BFS

{% embed url="https://cp-algorithms.com/graph/01_bfs.html" %}

Cleaned version of Dijkstra's:

```cpp
d.assign(n, INF);
d[s] = 0;
set<pair<int, int>> q;
q.insert({0, s});
while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());

    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;

        if (d[v] + w < d[u]) {
            q.erase({d[u], u});
            d[u] = d[v] + w;
            q.insert({d[u], u});
        }
    }
}
```

0-1 BFS (use deque to adjust state checking order instead of priority queue with cost and state)

<pre class="language-cpp"><code class="lang-cpp"><strong>vector&#x3C;int> d(n, INF);
</strong>d[s] = 0;
deque&#x3C;int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    // can use dirs for bfs as well (e.g. up down left right)
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w &#x3C; d[u]) {
            d[u] = d[v] + w;
            // if cost increases, process it later
            if (w == 1)
                q.push_back(u);
            // else continue bfs
            else
                q.push_front(u);
        }
    }
}
</code></pre>

LeetCode 2290: [https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner)

```cpp
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        deque<pair<int, int>> dq;

        dp[0][0] = 0;
        dq.push_front({0, 0});
        visited[0][0] = true;

        while (!dq.empty()) {
            auto [x, y] = dq.front(); 
            dq.pop_front();
            for (int i = 0; i < 4; ++i) {
                int _x = x + dirs[i].first;
                int _y = y + dirs[i].second;
                if (_x >= 0 && _y >= 0 && _x < m && _y < n && !visited[_x][_y]) {
                    dp[_x][_y] = dp[x][y] + (grid[_x][_y] == 1);
                    // 0-1 BFS, push to back if removed obstacle, instead of using priority queue to sort by cost
                    if (grid[_x][_y]) dq.push_back({_x, _y});
                    else dq.push_front({_x, _y});
                    visited[_x][_y] = true;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
```

In summary: pretty cool shit.&#x20;
