# Comparison of Radix Sort and Quick Sort

## 1. Theoretical Comparison

| Criterion | Radix Sort (LSD, base 10) | Quick Sort | 
| ----- | ----- | ----- | 
| Type | Non-comparative | Comparative | 
| Time Complexity | O(d * (n + 10)), d is the number of digits of the maximum value | Average O(n log n), worst O(n²) | 
| Extra Space Complexity | O(n + 10) | Average O(log n) for recursion stack; worst O(n) with middle pivot | 
| Stability | Yes | No (in-place swap version) | 
| Data Conditions | Non-negative integers | Any comparable type | 

## 2. Experimental Results

**Measurement method.** Each algorithm sorts a copy of the same data, taking the minimum time out of 3 runs. Only sorting time is measured.

### 2.1. Random Data

| Scenario | n | Number of digits d | Radix (ms) | Quick (ms) | 
| ----- | ----- | ----- | ----- | ----- | 
| a. small range 0-99 | 10⁶ | 2 | 7.03 | 35.38 | 
| a2. medium range 0-10⁶ | 10⁶ | 7 | 20.25 | 82.04 | 
| b. 100 distinct values, range 0-2*10⁹ | 10⁶ | 10 | 41.89 | 33.90 | 
| c. uniform random 0-2*10⁹ | 10⁶ | 10 | 39.92 | 83.21 | 
| a. small range 0-99 | 10⁷ | 2 | 163.44 | 368.13 | 
| a2. medium range 0-10⁶ | 10⁷ | 7 | 508.82 | 859.05 | 
| b. 100 distinct values, range 0-2*10⁹ | 10⁷ | 10 | 963.07 | 372.37 | 
| c. uniform random 0-2*10⁹ | 10⁷ | 10 | 993.99 | 957.90 | 

### 2.2. Edge Cases and Special Data

| No. | Case | n | Radix (ms) | Quick (ms) | Correct Result | 
| ----- | ----- | ----- | ----- | ----- | ----- | 
| 1 | Empty array | 0 | error (crash) | ≈ 0 | Quick only | 
| 2 | 1-element array | 1 | ≈ 0 | ≈ 0 | Yes | 
| 3 | All values identical | 10⁶ | 35.28 | 13.24 | Yes | 
| 4 | Already sorted ascending | 10⁶ | 27.43 | 7.73 | Yes | 
| 5 | Sorted descending | 10⁶ | 26.68 | 7.59 | Yes | 
| 6 | Only two boundary values 0 and 1,000,000 | 10⁶ | 38.60 | 21.47 | Yes | 
| 7 | Values with different number of digits (5, 42, 802, 1000000) | 10⁶ | 35.40 | 19.66 | Yes | 
| 3 | All values identical | 10⁷ | 596.98 | 179.54 | Yes | 
| 4 | Already sorted ascending | 10⁷ | 561.75 | 150.66 | Yes | 
| 5 | Sorted descending | 10⁷ | 600.25 | 113.83 | Yes | 
| 6 | Only two boundary values 0 and 1,000,000 | 10⁷ | 698.44 | 173.20 | Yes | 
| 7 | Values with different number of digits (5, 42, 802, 1000000) | 10⁷ | 573.84 | 215.95 | Yes | 

## 3. Observations

- With random data, Radix Sort is faster than Quick Sort when the number of digits d is small: about 5 times (d = 2), 2-4 times (d = 7). When d = 10 (scenario c), the advantage is almost lost at n = 10⁷ (994 ms vs 958 ms).
- Quick Sort is clearly faster in scenario b (many duplicate values, only 100 distinct values): about 1.2 times at n = 10⁶ and 2.6 times at n = 10⁷. Radix Sort does not take advantage of duplicate values.
- With special data (2.2), Quick Sort is about 2-5 times faster than Radix Sort: already sorted, reverse sorted, and all identical values are easy cases for Quick Sort (middle pivot, does not degrade to O(n²)), but Radix Sort still has to run all d passes.
- Radix Sort requires data to be non-negative integers, and this implementation crashes with an empty array, while Quick Sort correctly handles all edge cases.

## 4. Algorithm Selection

| Situation | Recommended | 
| ----- | ----- | 
| Non-negative integers, few digits (codes, scores, age, short IDs) | Radix Sort | 
| Very large integers (many digits) or many duplicate values | Quick Sort | 
| Non-integer data (uneven long strings, objects) | Quick Sort | 
| Need to maintain the order of equal elements | Radix Sort (or another stable sort) | 
| Data is already sorted or nearly sorted, very small array, or limited memory | Quick Sort | 
