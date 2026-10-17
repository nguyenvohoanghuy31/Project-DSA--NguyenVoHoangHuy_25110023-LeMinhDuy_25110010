# Week 2 Report: Radix Sort

## 1. Algorithm

The Radix Sort code works by classifying and sorting elements based on each of their digits (or characters), going from the units place, the tens place, the hundreds place, ...

Steps:

1. Find the maximum value to determine the number of digits `d` to process.
2. For each digit position, from least to most significant (units, tens, hundreds, ...), put each element into the bucket matching its digit at that position.
3. Collect the buckets from 0 to 9 back into the array, keeping the original order inside each bucket (stable).

## 2. Complexity

| Criterion | Value          |
| --------- | -------------- |
| Time      | O(d * (n + b)) |

Where `n` is the number of elements in the array, `d` is the number of digits of the largest value, and `b` is the base (b = 10, the number of buckets).

## 3. Testing

### 3.1. Normal example

An array with several different values, possibly with duplicates, is sorted in ascending order with the correct result.

### 3.2. Edge cases

| No. | Case                                                             |
| --- | ---------------------------------------------------------------- |
| 1   | Empty array                                                      |
| 2   | Array with 1 element                                             |
| 3   | All values identical                                             |
| 4   | Already sorted ascending                                         |
| 5   | Sorted descending                                                |
| 6   | Values 0 and 1,000,000                                           |
| 7   | Values with different digit counts (e.g. 5, 42, 802, 1000000)    |

### 3.3. Invalid input

| No. | Case                        |
| --- | --------------------------- |
| 1   | Negative number             |
| 2   | Value exceeding 1,000,000   |
| 3   | Negative number of elements |

### 3.4. Large input

- `n = 1,000,000`
- Random values in the range `[0, 1000000]`
## 4. Test Generation

No AI tools were used to generate tests this week. The tests in Section 3 are reused from the Week 1 report (Counting Sort), since both algorithms process the same kind of input (non-negative integers in the range `[0, 1000000]`) and share the same edge cases, invalid inputs, and large-input scenario.
