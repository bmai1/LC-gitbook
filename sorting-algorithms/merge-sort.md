---
description: i also call this the two balls & penis sort !
---

# 🤪 merge sort

```cpp
// O(nlogn) time 
// O(n) space [left/right subarrays]

// 2.3.1 Divide and Conquer
// - divide into subproblems
// - conquer subproblems by solving recursively
// - combine subsolution
// - Merge Sort follows div/conq paradigm
//     - Intuition: 2 subsequ (n/2 elements), recursive sort, merge sorted subseq
//     - Recursion stops when subseq length == 1


#include "../bits/stdc++.h"
using namespace std; 


void merge(vector<int>& A, int left, int mid, int right) { 
    // size of subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // left/right arrays, extra pos holds sentinel 
    vector<int> L(n1);
    vector<int> R(n2);

    // copies values into subarrays
    for (int i = 0; i < n1; ++i) {
        L[i] = A[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = A[mid + 1 + j];
    }

    // // "sentinel card" cannot be smaller unless both piles have sentinel card exposed
    // L[n1] = INFINITY;
    // R[n2] = INFINITY;

    int i = 0;
    int j = 0;
    int k = left;

    // loop invariant (merge tmp arrays)
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining of left and right
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& A, int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    mergeSort(A, begin, mid);
    mergeSort(A, mid + 1, end);
    merge(A, begin, mid, end);
}


int main() {
    vector<int> A = { 1,2,4,6,5,3 };
    // algorithm goes here
    mergeSort(A, 0, A.size() - 1);
    for (int n : A) {
        cout << n;
    }
    cout << endl;
    return 0; 
}
```
