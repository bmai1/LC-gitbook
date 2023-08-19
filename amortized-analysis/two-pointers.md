# 👹 two pointers

Concept: Two ptrs iterate through A (one at first and last index of SA), each move 1 dir

```
Applicability of 2ptr depends on relation of window scopes:
 1. If a wider scope is invalid, narrower scope must also be invalid
 2. If a wider scope of the sliding window is valid, the narrower scope of that wider scope must remain (potentially) valid
 - vice versa, contrapositive
 
- Subarray Sum: 
  On each turn, the left pointer moves one step to the right, 
  right pointer moves to the right as long as the resulting subarray sum is at most x
  If the sum becomes exactly x, a solution has been found.
```
