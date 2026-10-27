# Comparison of Counting Sort and Quick Sort

## 1. Theoretical Comparison

| Criterion | Counting Sort | Quick Sort | 
| ----- | ----- | ----- | 
| Type | Non-comparative (distribution) | Comparative | 
| Time Complexity | O(n + k) | Average O(n log n), worst O(n²) | 
| Auxiliary Memory | O(n + k) | Average O(log n) for recursion stack; worst O(n) with middle pivot | 
| Stability | Yes (if traversing backwards when placing) | No (in-place swap version) | 
| Data Conditions | Integers in a known range [0, k] | Any comparable type | 

## 2. Experimental Results

**Measurement method.** Each algorithm sorts a copy of the same data, taking the minimum time out of 3 runs. Only sorting time is measured.

### 2.1. Random Data

| Scenario | n | k (value range) | Counting (ms) | Quick (ms) | 
| ----- | ----- | ----- | ----- | ----- | 
| a. small range 0-99 | 10⁶ | 99 | 1.04 | 36.00 | 
| a2. medium range 0-10⁶ | 10⁶ | 10⁶ | 12.07 | 84.43 | 
| b. 100 distinct values, range 0-2·10⁹ | 10⁶ | 2·10⁹ | cannot run (k > 10⁶) | 42.21 | 
| c. uniform random 0-2·10⁹ | 10⁶ | 2·10⁹ | cannot run (k > 10⁶) | 93.90 | 
| a. small range 0-99 | 10⁷ | 99 | cannot run (n > 10⁶) | 362.53 | 
| a2. medium range 0-10⁶ | 10⁷ | 10⁶ | cannot run (n > 10⁶) | 935.83 | 
| b. 100 distinct values, range 0-2·10⁹ | 10⁷ | 2·10⁹ | cannot run (n > 10⁶) | 398.49 | 
| c. uniform random 0-2·10⁹ | 10⁷ | 2·10⁹ | cannot run (n > 10⁶) | 1017.43 | 

### 2.2. Edge Cases and Special Data

| No. | Case | n | Counting (ms) | Quick (ms) | Correct Result | 
| ----- | ----- | ----- | ----- | ----- | ----- | 
| 1 | Empty array | 0 | 0.36 | ≈ 0 | Yes | 
| 2 | 1-element array | 1 | 0.35 | ≈ 0 | Yes | 
| 3 | All values identical | 10⁶ | 3.12 | 12.64 | Yes | 
| 4 | Already sorted ascending | 10⁶ | 1.68 | 7.38 | Yes | 
| 5 | Sorted descending | 10⁶ | 1.78 | 6.92 | Yes | 
| 6 | Only two boundary values 0 and 1,000,000 | 10⁶ | 2.27 | 15.12 | Yes | 
| 7 | Values with different number of digits (5, 42, 802, 1000000) | 10⁶ | 1.57 | 20.97 | Yes | 
| 3 | All values identical | 10⁷ | cannot run (n > 10⁶) | 145.91 | Yes | 
| 4 | Already sorted ascending | 10⁷ | cannot run (n > 10⁶) | 120.69 | Yes | 
| 5 | Sorted descending | 10⁷ | cannot run (n > 10⁶) | 123.70 | Yes | 
| 6 | Only two boundary values 0 and 1,000,000 | 10⁷ | cannot run (n > 10⁶) | 191.60 | Yes | 
| 7 | Values with different number of digits (5, 42, 802, 1000000) | 10⁷ | cannot run (n > 10⁶) | 235.12 | Yes | 

## 3. Observations

- When n = 10⁶, Counting Sort is faster than Quick Sort by about 35 times (k = 99) and about 7 times (k = 10⁶). The larger the value range k, the lower the performance.
- At n = 10⁷, Counting Sort cannot run due to the implementation's `MAX_LENGTH` limitation, whereas Quick Sort runs across all scenarios.
- Quick Sort does not degrade to O(n²) on sorted, reverse sorted, or all-identical value data. Counting Sort remains about 4-13 times faster and is almost independent of data ordering.
- With an empty array or a 1-element array, both give correct results, but Counting Sort still takes about 0.35 ms because it always scans the entire count array.

## 4. Algorithm Selection

| Situation | Recommended | 
| ----- | ----- | 
| Integers, small and known value range (scores, ages, small IDs) | Counting Sort | 
| Very large or unknown value range | Quick Sort | 
| Non-integer data (strings, objects) | Quick Sort | 
| Need to maintain the order of equal elements | Counting Sort (or another stable sort) | 
| Limited memory, or n exceeds implementation array limit | Quick Sort | 
