# 🥂 champagne tower

#### Approach 1: right pyramid memoization

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[100][101] = {}; 
        dp[0][1] = poured; // 1-index glass so can check left 
        for (int i = 1; i <= query_row; ++i) {
            for (int j = 1; j < i + 2; ++j) {
                dp[i][j] += max((dp[i - 1][j - 1] - 1) / 2.0, 0.0) + max((dp[i - 1][j] - 1) / 2.0, 0.0);
            }
        }
        return min(1.0, dp[query_row][query_glass + 1]);
    }
};
```

#### Approach 2: two vector memoization (prev and curr row)

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev = {(double) poured};
        for (int i = 1; i <= query_row; ++i) {
            vector<double> curr = vector<double>(i + 1, 0);
            for (int j = 0; j < i; ++j) {
                double extra = prev[j] - 1;
                if (extra > 0) {
                    curr[j]     += 0.5 * extra;
                    curr[j + 1] += 0.5 * extra;
                }
            }
            prev = curr;
        }
        return min(1.0, prev[query_glass]);
    }
};
```
