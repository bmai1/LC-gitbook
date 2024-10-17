---
description: 'Time complexity: O(n + m), n-nodes, m-edges'
---

# 🥵 dfs

#### ver 1. recursive dfs template

```cpp
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
    if (i < 0 || j < 0 || i < grid.size() || j < grid[0].size()) return;
    if (condition || visited[i][j]) return;
    visited[i][j] = true;
    // do something
    dfs(grid, visited, i + 1, j);
    dfs(grid, visited, i - 1, j);
    dfs(grid, visited, i, j + 1);
    dfs(grid, visited, i, j - 1);
}
```

* base cases to end recursion: within boundaries? visited cell already?
* mark cell as visited (can be done in place without allocating extra memory)
* deeply searches neighbors 😏

#### ver 2.  iterative dfs via stack template

```cpp
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int startRow, int startCol) {
    stack<pair<int, int>> s;  // hold cell coordinates
    s.push({startRow, startCol});
    
    while (!s.empty()) {
        pair<int, int> curr = s.top(); s.pop();
        int i = curr.first, int j = curr.second;

        // separate base cases for clarity
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1) continue;
        if (visited[i][j]) continue;

        visited[row][col] = true; 

        // add neighboring cells to stack to search
        s.push({i + 1, j}); 
        s.push({i - 1, j});  
        s.push({i, j + 1});  
        s.push({i, j - 1}); 
    }
}
```

* same idea, just using a stack and while loop instead of recursion
* can be somewhat easier to manage memory and avoid stack overflow

#### ver 3. graph dfs

```cpp
vector<int> adj[N]; // adjacency list
bool visited[N];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    // process node s
    for (auto u: adj[s]) {
        dfs(u); 
    }
}
```
