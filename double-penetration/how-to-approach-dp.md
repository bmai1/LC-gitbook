# 😰 how to approach dp

Dynamic programming involves solving a _recurrence relation_ (a formula where the next term is a function of previous terms) to find an optimized, as in min/maxed, solution to a given problem.

* To improve efficiency and memory usage, **memoization** is a technique to store results of sub-problems instead of recalculating redundantly. These results are then used to find the final answer.

Generally, there are a few stages to solving a dp problem:

* Find the recursive relation **(MOST IMPORTANT!)**
* Recursive top-down (start from end, recursively call backwards)
* Recursive top-down memoized
* Iterative bottom-up memoized (start from beginning and loop to end)
* Optimized memory iterative (N variables)
