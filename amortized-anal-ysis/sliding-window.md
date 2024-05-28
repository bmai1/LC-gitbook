---
description: i hate this even though it's not conceptually difficult
---

# 🪟 sliding window

### Two Types of Sliding Windows:

1. Fixed-sized
2. Variable-sized (shrinkable) window

Fixed-size: Constant subarray that goes from left to right (or backwards) through the array.

Example:

```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    // calculate the sum of the first window
    int maxSum = 0;
    for (int i = 0; i < k; ++i)
        maxSum += arr[i];

    int windowSum = maxSum;
    for (int i = k; i < n; ++i) {
        // arr[i - k] is no longer in the window as it moves to the right
        windowSum += arr[i] - arr[i - k];
        // do whatever you need to do with current valid window
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
```

Variable-size: start and end (lo/hi, left/right) variables that shrink the window

Example:

```cpp
int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    int minLength = INT_MAX;
    int left = 0;
    int sum = 0;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];
        
        // move start pointer up to shrink window
        while (sum >= s) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
    }

    return (minLength == INT_MAX) ? 0 : minLength;
}
```

### Max Sliding Window Templates&#x20;

Template 1. (shrinkable)

```cpp
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
```

Template 2. (non-shrinkable)

```cpp
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
```
