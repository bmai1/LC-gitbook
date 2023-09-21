# 😹 backtracking intuition

Backtracking is <mark style="color:yellow;">quite similar to brute force</mark>, but through a recursive function with a base case, we can avoid unnecessary calculations for states that aren't valid. &#x20;

* For each state, we try the nextState and then revert to old state to check all possibilities

#### General recursive template:

```cpp
void backtrack(states, currState) {
    if (!condition(currState)) return; 
    
    // do something
    
    for (? in states) {
        state = nextState // turn into nextState and try solution
        backtrack(state, nextState(?));
        state.revert(); // revert to old state
    }
}
```

Example: 1863 - Subset XOR Sum

```cpp
class Solution {
private: 
    int ans = 0; 
    void backtrack(vector<int>& nums, vector<int>& ss, int start) {
        int ssxor = 0;
        for (int n : ss) ssxor ^= n;
        ans += ssxor;
        for (int j = start; j < nums.size(); ++j) {
            ss.push_back(nums[j]);
            backtrack(nums, ss, j + 1);
            ss.pop_back();
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ss;
        backtrack(nums, ss, 0);
        return ans;
    }
};
```
