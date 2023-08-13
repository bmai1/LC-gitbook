# 🥴 binary search

Binary search generally requires a sorted list of elements, but can also be applied to more complex problems. It has a time complexity of O(logn).

### Intuition:

Initialize low and high (a.k.a left/right, start/end) pointers. Determine the middle index and adjust the start and end pointers with a conditional such that the number of remaining potential answers is halved, and the answer is guaranteed to be found in the new window.

### Generalized template:

```python
def binary_search(array) -> int:
    def condition(value) -> bool:
        pass

    lo = 0, hi = len(array)
    while lo < hi: # lo <= hi ?
        mid = lo + (hi - lo) / 2
        if condition(mid):
            lo = mid 
        else:
            hi = mid + 1
    return lo # mid, hi ? 
```

Important:

* left and right pointers initially cover all possibilities
* adjust boundaries (lo <= hi, mid = hi + lo / 2,)
* design inner conditional to adjust left and right index accordingly (mid, mid + 1, mid - 1, ?)
* decide return condition (lo, mid, hi, ?) to match problem