---
icon: trash-can
---

# monotonic stack

Stack in increasing/decreasing order

* Useful for finding next smaller/greater element based on a given order

```cpp
stack<int> stk;
vector<int> arr = {1, 2, 4, 5, 3, 4};

for (int n : arr) {
    int curr = n;

    // swap for monotonic decreasing
    while (!stk.empty() && stk.top() > curr) {
        // process removed elements
        stk.pop();
    }
    
    stk.push(curr); // guaranteed to be the largest element in stack
}

// stk = {1, 2, 3, 4}
```

LeetCode 1475, 496, 739
