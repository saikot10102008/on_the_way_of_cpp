**Bubble sort** is one of the simplest sorting algorithms to understand, which is exactly why it is taught so often at the beginning. Its core idea is very intuitive: repeatedly look at every pair of **adjacent** elements in the array and, if they are in the wrong order, swap them. After doing this many times, the largest (or smallest) values slowly “bubble” toward the correct end of the array — hence the name.

The algorithm works in passes. In each pass, we go from the beginning of the array almost to the end, comparing every two neighboring elements and swapping them whenever the left one is larger than the right one (for ascending order). Because of these adjacent swaps, after the **first complete pass**, the single largest value in the entire array has definitely moved all the way to the very last position — it has “bubbled up” to the end. After the second pass, the second-largest value reaches the second-to-last position, and so on. This is why, in each new pass, we can safely ignore one more element at the end — we already know those positions contain correctly sorted (largest) values. So in the i-th pass we only need to look at the first (n−i−1) pairs.

The classic double-loop structure therefore looks like this conceptually:

- outer loop → controls the number of passes (usually runs n−1 times at worst)
- inner loop → walks through the still-unsorted part of the array and performs adjacent comparisons + swaps

Because of the way the biggest remaining element travels to its final place in every pass, bubble sort belongs to the family of **comparison-based, in-place, stable** sorting algorithms. However, its performance is poor: in the average and worst case it always performs Θ(n²) comparisons and Θ(n²) swaps, making it dramatically slower than quicksort, mergesort, heapsort or even insertion sort for medium-to-large arrays.

A small but very important practical improvement is the “early termination” flag: if during one full pass no swaps happened at all, the array is already sorted → we can stop immediately instead of doing all remaining useless passes. With this tiny addition (often called “optimized bubble sort”), the algorithm becomes adaptive and can finish in O(n) time on already sorted or nearly sorted data — but even then, it is still not competitive with better adaptive sorts (insertion sort, timsort) in most real-world cases.

In short: bubble sort is educationally beautiful because its logic is immediately visible — you can literally watch the values bubble step-by-step — but almost never used in serious software because far more efficient alternatives exist for every realistic input size.
