## 1. Build/Run Instructions

### 1.1. Requirements

- `g++` compiler with C++17 support.
- Source files located in the root directory of the repo: `counting_sort.cpp`, `Radixsort.cpp`, `Quicksort.cpp`.

### 1.2. Build

```bash
g++ -std=c++17 -O2 counting_sort.cpp -o counting_sort
g++ -std=c++17 -O2 Radixsort.cpp -o Radixsort
g++ -std=c++17 -O2 Quicksort.cpp -o Quicksort
```

### 1.3. Input Format

- Line 1: number of elements `n`.
- Line 2: `n` integers, separated by spaces.

Example:

```text
8
170 45 75 45 802 24 2 66
```

Limits of each program:

| Program         | Input Limits                                                                              |
| --------------- | ----------------------------------------------------------------------------------------- |
| Counting Sort   | n ≤ 10⁶, each value in [0, 10⁶]; values out of range will report an error and halt        |
| Radix Sort      | Non-negative integers, n ≥ 1 (empty array will cause an error), recommended value < 10⁹   |
| Quick Sort      | Any integer, n ≥ 0                                                                        |

## 2. Hand-calculated example and comparison with program results

**Data:** `n = 8`, array `[170, 45, 75, 45, 802, 24, 2, 66]` (contains duplicate values: 45 appears 2 times).

**Expected result:** `2 24 45 45 66 75 170 802`.

### 2.1. Counting Sort (hand-calculated)

Step 1: count the occurrences (only list values with `cnt > 0`):

| Value `j`   | 2 | 24 | 45 | 66 | 75 | 170 | 802 |
| ----------- | - | -- | -- | -- | -- | --- | --- |
| `cnt[j]`    | 1 | 1  | 2  | 1  | 1  | 1   | 1   |

Step 2: iterate `j` from 0 to `MAX_ELEMENT`, for each `j` write the value `j` to the array `cnt[j]` times:

`2` -> `24` -> `45, 45` -> `66` -> `75` -> `170` -> `802`

Result: `2 24 45 45 66 75 170 802`.

### 2.2. Radix Sort (hand-calculated)

The maximum value is 802 (3 digits), so there are 3 passes: ones, tens, hundreds place (`hang` = 1, 10, 100). After each pass, the buckets are concatenated in the order of bucket 0 -> 9, maintaining the original order within each bucket.

| Pass          | Bucket (digit: elements)                                 | Array after pass              |
| ------------- | -------------------------------------------------------- | ----------------------------- |
| 1 (hang = 1)  | 0: 170 - 2: 802, 2 - 4: 24 - 5: 45, 75, 45 - 6: 66       | 170 802 2 24 45 75 45 66      |
| 2 (hang = 10) | 0: 802, 2 - 2: 24 - 4: 45, 45 - 6: 66 - 7: 170, 75       | 802 2 24 45 45 66 170 75      |
| 3 (hang = 100)| 0: 2, 24, 45, 45, 66, 75 - 1: 170 - 8: 802               | 2 24 45 45 66 75 170 802      |

Result: `2 24 45 45 66 75 170 802`. The two 45s maintain their original order throughout the passes, illustrating the stability of Radix Sort.

### 2.3. Quick Sort (hand-calculated)

The program selects the pivot as the middle element `a[l + (r - l) / 2]`, using two pointers `i` (from the left) and `j` (from the right).

| Segment `[l, r]` | Array segment                 | Pivot | Swaps                               | After partition                   |
| -------------- | ----------------------------- | ----- | ----------------------------------- | --------------------------------- |
| [0, 7]         | 170 45 75 45 802 24 2 66      | 45    | (170, 2), (45, 24), (75, 45)        | 2 24 45 \ 75 802 45 170 66        |
| [0, 2]         | 2 24 45                       | 24    | none                                | already in order                  |
| [3, 7]         | 75 802 45 170 66              | 45    | (75, 45)                            | 45 \ 802 75 170 66                |
| [4, 7]         | 802 75 170 66                 | 75    | (802, 66)                           | 66 75 \ 170 802                   |
| [6, 7]         | 170 802                       | 170   | none                                | already in order                  |

Reassemble: `2 24 45 45 66 75 170 802`.

### 2.4. Comparison with program

Running with the input file containing:

```text
8
170 45 75 45 802 24 2 66
```

The output results of all three programs:

```text
After sorting: 2 24 45 45 66 75 170 802       (counting_sort)
Array after sorting: 2 24 45 45 66 75 170 802 (Radixsort)
Array after sorting: 2 24 45 45 66 75 170 802 (Quicksort)
```

| Algorithm       | Hand-calculated result       | Program result               | Match |
| ------------- | ---------------------------- | ---------------------------- | ----- |
| Counting Sort | 2 24 45 45 66 75 170 802     | 2 24 45 45 66 75 170 802     | Yes   |
| Radix Sort    | 2 24 45 45 66 75 170 802     | 2 24 45 45 66 75 170 802     | Yes   |
| Quick Sort    | 2 24 45 45 66 75 170 802     | 2 24 45 45 66 75 170 802     | Yes   |
