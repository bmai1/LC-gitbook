# 😏 brutal (complete search)

recursively generate all subsets of set {0,1,...,n-1}

```cpp
void search(int k) {
  if (k == n) {
    // process subset
  } 
  else {
    search(k + 1);
    subset.push_back(k);
    search(k + 1);
    subset.pop_back();
  } 
}
```

generate permutations (C++ STL)

```cpp
vector<int> permutation;
for (int i = 0; i < n; i++) {
    permutation.push_back(i);
}
do {
    // process permutation
} while (next_permutation(permutation.begin(), permutation.end()));
```
