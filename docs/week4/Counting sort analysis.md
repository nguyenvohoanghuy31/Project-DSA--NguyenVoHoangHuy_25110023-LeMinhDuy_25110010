# Data Tables and Analysis of Counting Sort

## 1. Data tables

The data was measured by a program. Unit: milliseconds (ms), averaged over 5 runs (n ≤ 10,000), 5 runs (n = 100,000), 5 runs (n = 1,000,000) and 3 runs (k ≥ 10,000,000). Both algorithms ran on the same dataset, and the sorted result of every run was checked against `std::sort`. Quick Sort uses the middle element as the pivot and swaps in place.

### 1.1. Increasing n, small fixed k (k = 1,000)

| n         | Data type | k     | Counting Sort (ms) | Quick Sort (ms) | Quick / Counting |
| --------- | --------- | ----- | ------------------ | --------------- | ---------------- |
| 1,000     | Random    | 1,000 | < 0.01             | 0.04            | ≈ 13             |
| 10,000    | Random    | 1,000 | 0.03               | 0.67            | 23.45            |
| 100,000   | Random    | 1,000 | 0.24               | 6.35            | 26.05            |
| 1,000,000 | Random    | 1,000 | 2.49               | 74.04           | 29.76            |

### 1.2. Fixed n = 1,000,000, increasing k

| n         | k           | Counting Sort (ms) | Quick Sort (ms) | Quick / Counting |
| --------- | ----------- | ------------------ | --------------- | ---------------- |
| 1,000,000 | 1,000       | 2.43               | 72.27           | 29.78            |
| 1,000,000 | 100,000     | 4.04               | 102.93          | 25.51            |
| 1,000,000 | 1,000,000   | 18.91              | 109.21          | 5.78             |
| 1,000,000 | 10,000,000  | 65.42              | 110.38          | 1.69             |
| 1,000,000 | 100,000,000 | 465.65             | 106.58          | 0.23             |

### 1.3. n = 1,000,000, k = 1,000,000, by data type

| n         | Data type                            | Counting Sort (ms) | Quick Sort (ms) | Quick / Counting |
| --------- | ------------------------------------ | ------------------ | --------------- | ---------------- |
| 1,000,000 | Random                               | 24.73              | 110.52          | 4.47             |
| 1,000,000 | Already sorted (ascending)           | 10.30              | 23.75           | 2.31             |
| 1,000,000 | Sorted in descending order           | 11.29              | 24.23           | 2.15             |
| 1,000,000 | Many duplicates (values 0..10)       | 4.20               | 43.86           | 10.45            |
| 1,000,000 | All values identical                 | 5.99               | 29.78           | 4.97             |

## 2. Analysis

- **When k is small relative to n:** Counting Sort is about 13 to 30 times faster than Quick Sort, and the gap widens as n grows. When n grows 10 times, Counting Sort's running time grows about 10 times, consistent with the near-linear O(n + k). Quick Sort grows about 11.7 times, slightly above linear because of the log n factor.
- **When k grows:** Counting Sort's running time and memory grow with k. With n = 1,000,000, Counting Sort goes from being 29.78 times faster, down to 1.69 times faster at k = 10,000,000 (10 times n), and then about 4.4 times slower than Quick Sort at k = 100,000,000 (100 times n). The break-even point lies roughly between k = 10n and k = 100n. Quick Sort's running time stays almost unchanged as k grows.

## 3. Why Counting Sort is not bounded by n log n

1. **The n log n bound only applies to comparison-based sorting.** There are n! different orderings of n elements. Each comparison has only 2 outcomes, so the decision tree must have at least n! leaves and a height of at least log₂(n!) = Θ(n log n).
2. **Counting Sort never compares two elements with each other.** It uses the element's own value as an index into the counting array. Each step is no longer limited to 2 outcomes, so the decision-tree argument does not apply, and the algorithm reaches O(n + k).
3. **The price is a restriction on the data.** Counting Sort only works on integers in a known range [0, k]. When k is much larger than n, O(n + k) is dominated by k, costing both time and memory. Section 1.2 shows this: at k = 100,000,000 (100 times n), Counting Sort is about 4.4 times slower than Quick Sort and needs about 400 MB.

## 4. Conclusion

Counting Sort gets past the n log n limit because it is not comparison-based. When k is small relative to n, it is tens of times faster than Quick Sort in practice. This advantage disappears once k exceeds n by about one to two orders of magnitude, and Quick Sort becomes the better choice.
