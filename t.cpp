
///////////////////////////////////////////////////////////////////////////////// SEARCH

// ver 1. recursive dfs template
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

// ver 2.  iterative dfs via stack template
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

// ver 1. iterative bfs via queue template
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

///////////////////////////////////////////////////////////////////////////////// WINDOW 

// ver. 1 shrinkable window template
int left = 0, right = 0, ans = 0;
for (; right < N; ++right) {
    // use A[right] to update state
    for (; invalid(); ++left) { 
        // while invalid keep shrinking the left edge until it's valid again
        // update state using A[left]
    }
    ans = max(ans, right - left + 1); // window [left, right] is the maximum window we've found thus far
}
return ans;

// ver 2. non-shrinkable window template
int l = 0, r = 0;
for (; r < N; ++r) {
    // use A[right] to update state
    if (invalid()) { // Increment the left edge ONLY when the window is invalid. 
        // window GROWs when valid, and SHIFTs when invalid
        // update state using A[left]
        ++l;
    }
    // after `++r` in the for loop, this window `[l, r]` of length `r - l` MIGHT be valid.
}
return r - l; // There must be a maximum window of size `j - i`

///////////////////////////////////////////////////////////////////////////////// BACKTRACKING

// general recursive check states template 
void backtrack(states, currState) {
    if (!condition(currState)) return; 
    // do something
    for (? in states) {
        backtrack(state, nextState(?));
    }
}
