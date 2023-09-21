# 😰 how to approach dp

Dynamic programming <mark style="color:yellow;">involves</mark> <mark style="color:yellow;">solving a</mark> <mark style="color:yellow;"></mark>_<mark style="color:yellow;">recurrence relation</mark>_ (a formula where the next term is a function of previous terms) to find solution to a given problem through smaller subproblems.

#### Uses: optimal solution, count number of solutions

* To improve efficiency and memory usage, <mark style="color:green;">**memoization**</mark> is a technique which involves storing results of sub-problems instead of recalculating redundantly. These results are then used to find the final answer.
* Dynamic Programming consists of states and transitions; states being the variables to memoize and transitions being the method to convert prior values to current value

Generally, there are a few stages to formulating (and optimizing) a dp problem solution:

1. Find the recursive relation **(MOST IMPORTANT!)**
2. Recursive top-down (start from end, recursively call backwards)
3. Recursive top-down memoized
4. Iterative bottom-up memoized (start from beginning and loop to end)
5. Optimized memory iterative (N variables)
