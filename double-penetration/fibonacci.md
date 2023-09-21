# 🦈 fibonacci

```cpp
// Skiena 8.1.3 Example: Fibonacci (find nth fib)

Recursive approach:
def fib(n):
    if n <= 1 return n
    return fib(n - 1) + fib(n - 2)

Caching (Memoization):
def fib(n):
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];

Optimization (time/memory), O(n) time, O(1) space:
def fib(n):
    int pp = 0;
    int p = 1;
    for (int i = 2; i <= n; ++i) {
        // store
        int n = p + pp;
        // shift up
        pp = p;
        // reassign
        p = n;
    }
    return p + pp;
```
