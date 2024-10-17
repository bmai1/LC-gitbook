---
icon: face-hand-yawn
---

# selection sort

O(n²), Select the min (or max) from unsorted part and swap.

```java
void selectionSort(int nums[]) {
    for (int i = 0; i < nums.length; ++i) {
        int m = i;
        for (int j = i + 1; j < nums.length; ++j) {
            // reverse to sort in descending
            if (nums[m] > nums[j]) m = j;
        }
        if (i != m) swap(nums[i], nums[m]);
    }
}
```
