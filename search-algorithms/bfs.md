---
description: 'Time complexity: O(n + m), n-nodes, m-edges'
---

# 🍆 bfs

#### ver 1. iterative bfs via queue template

```cpp
void bfs(vector<vector<int>>& grid, int startRow, int startCol) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;  // hold cell coordinates
    q.push({startRow, startCol});
    
    vector<int> dir = {-1, 0, 1, 0, -1}; // adj coords
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        // check neighbors
        for (int i = 0; i < 4; ++i) {
            int row = curr.first + dir[i];
            int col = curr.second + dir[i + 1];
            if (row >= 0 && row < m && col >= 0 && col < n && condition) {
                // do something
                q.push({row, col}); // update search queue
            }
        } 
    }
}
```
