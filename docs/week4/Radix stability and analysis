# Stability and Analysis of Radix Sort

## 1. Is Radix Sort stable?

Yes. A sorting algorithm is stable if two elements with the same key keep their original relative order. In `Radixsort.cpp`, each pass puts the numbers into 10 buckets by the digit being examined using `push_back`, then collects them from bucket 0 to bucket 9. Within a bucket, whichever number went in first comes out first, so two numbers with the same digit are never swapped. Because the passes go from the lowest digit to the highest, the order produced by earlier passes is preserved for later passes.

Example with (key, label) pairs `(21, a), (13, b), (21, c), (13, d)`:

| Step                      | Result                             |
| ------------------------- | ---------------------------------- |
| Initial                   | (21, a), (13, b), (21, c), (13, d) |
| After the units-digit pass | (21, a), (21, c), (13, b), (13, d) |
| After the tens-digit pass | (13, b), (13, d), (21, a), (21, c) |

In the final result, b is still before d and a is still before c, the same as at the start. An in-place Quick Sort does not guarantee this.

## 2. Experimental data

**Random data in [0, 1,000,000], increasing n:**

| n         | Radix Sort | Quick Sort | Quick / Radix |
| --------- | ---------- | ---------- | ------------- |
| 1,000     | 0.06       | 0.04       | 0.69          |
| 10,000    | 0.36       | 0.76       | 2.09          |
| 100,000   | 4.30       | 9.26       | 2.15          |
| 1,000,000 | 44.43      | 115.48     | 2.60          |

**n = 1,000,000, by data type:**

| Data type                         | Radix Sort | Quick Sort | Quick / Radix |
| --------------------------------- | ---------- | ---------- | ------------- |
| Random                            | 35.97      | 103.00     | 2.86          |
| Already sorted (ascending)        | 35.59      | 21.94      | 0.62          |
| Sorted in descending order        | 45.55      | 27.80      | 0.61          |
| Many duplicates (values 0..10)    | 13.88      | 43.31      | 3.12          |

From these two tables we can see:

- When n is large enough and the data is random, Radix Sort is about 2 to 3 times faster than Quick Sort. With n = 1,000, Quick Sort is faster, because Radix Sort spends time creating 10 vectors in every pass.
- Radix Sort takes almost the same time no matter how the data is arranged, while Quick Sort is clearly faster when the data already has some order. As a result, on already sorted data, Radix Sort is about 1.6 times slower than Quick Sort.

## 3. As integers get larger

In theory, Radix Sort has complexity O(d · (n + b)), where d is the number of digits of the largest value. When d is small it is almost linear. But the larger the numbers, the larger d becomes, so I kept n = 1,000,000 and gradually increased the largest value to see what happens:

| Largest value | d   | Radix Sort | Quick Sort | Quick / Radix |
| ------------- | --- | ---------- | ---------- | ------------- |
| 1,000         | 4   | 26.50      | 67.94      | 2.56          |
| 1,000,000     | 6   | 38.41      | 102.77     | 2.68          |
| 10⁹           | 9   | 60.37      | 101.68     | 1.68          |
| 2·10⁹         | 10  | 95.48      | 122.45     | 1.28          |

When d goes from 4 to 10, Radix Sort's running time grows about 3.6 times, more than the growth of d (2.5 times), probably because every pass has to copy the whole array into the buckets, so the cache works poorly. Quick Sort grows only about 1.8 times. As a result, Radix Sort's advantage shrinks from 2.56 times to 1.28 times. With the `int` type (maximum about 2.1·10⁹), Radix Sort is still faster, but if we switch to `long long` with numbers as large as 10¹⁸ (d = 19), it may no longer be faster than Quick Sort. This part is only an inference from the trend; I have not measured it.

## 4. Conclusion

Radix Sort is stable and faster than Quick Sort when the numbers are not too large and the data is random. However, when the integers grow larger or the data already has some order, that advantage shrinks or disappears. So when choosing an algorithm, we need to consider the shape of the data, not just the theoretical complexity.
