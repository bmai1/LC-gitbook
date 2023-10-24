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

#### example of applied iterative tree bfs:

```cpp
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
  
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int m = INT_MIN;
            // goes by row and finds the max
            for (int i = 0; i < n; ++i) {
                auto node = q.front(); q.pop();
                m = max(m, node->val);
                // these nodes are not processed immediately 
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(m);
        }
        return ans;
    }
};
```
