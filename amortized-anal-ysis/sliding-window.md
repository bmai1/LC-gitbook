# 🪟 sliding window

Idea: A fixed, <mark style="color:green;">constant-size subarray</mark> that goes from left to right (or backwards) through the array.

### Max Sliding Window&#x20;

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
