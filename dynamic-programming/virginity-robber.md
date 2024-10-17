# 🤑 virginity robber

Let's use [198. House Robber ](https://leetcode.com/problems/house-robber/description/?orderBy=most\_votes)to demonstrate each step of dp intuition.

### 1. Find recursive relation (most important step)

idk how just do it lol

### 2. Recursive top-bottom

```cpp
class Solution {
private: 
    int helper(vector<int>& nums, int i) {
        if (i < 0) return 0;
        return max(helper(nums, i - 2) + nums[i], helper(nums, i - 1));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, n - 1);
    }
};
```

### 3. Recursive top-bottom memoized

```cpp
class Solution {
private: 
    vector<int> dp;
    int helper(vector<int>& nums, int i) {
        if (i < 0) return 0;
        if (dp[i] >= 0) return dp[i];
        int res = max(helper(nums, i - 2) + nums[i], helper(nums, i - 1));
        dp[i] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return helper(nums, n - 1);
    }
};
```

### 4. Iterative bottom-top memoized

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[n];
    }
};
```

