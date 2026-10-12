# Week 1 Report: Counting Sort

## 1. Algorithm

The Counting Sort code uses a count array `cnt`, where the **index is the element's value**.

Steps:

1. Count the number of occurrences of each value in the input array.
2. Traverse the values from smallest to largest.
3. Write each value back into the result array according to the counted number of times.

## 2. Complexity

| Criterion | Value  |
| --------- | ------ |
| Time      | O(n + k) |

Where `n` is the number of elements in the array and `k` is the range of element values (the size of the count array `cnt`).

## 3. Testing

### 3.1. Normal example

An array with several different values, possibly with duplicates, is sorted in ascending order with the correct result.

### 3.2. Edge cases

| No. | Case                      |
| --- | ------------------------- |
| 1   | Empty array               |
| 2   | Array with 1 element      |
| 3   | All values identical      |
| 4   | Already sorted ascending  |
| 5   | Sorted descending         |
| 6   | Values 0 and 1,000,000    |

### 3.3. Invalid input

| No. | Case                         |
| --- | ---------------------------- |
| 1   | Negative number              |
| 2   | Value exceeding 1,000,000    |
| 3   | Negative number of elements  |

### 3.4. Large input

- `n = 1,000,000`
- Random values in the range `[0, 1000]`
