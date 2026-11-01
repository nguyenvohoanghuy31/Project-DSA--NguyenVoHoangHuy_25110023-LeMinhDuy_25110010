# Self-Reflection
## Lê Minh Duy (25110010)
 
**What I did:** implemented Radix Sort, compared Radix Sort with Quick Sort, and wrote the section on stability and the analysis of Radix Sort.
 
**What I understood:**
 
- Radix Sort is stable because each pass distributes the numbers into 10 buckets by digit using `push_back` and then collects them in bucket order, so numbers with the same digit keep their original order.
- The complexity O(d · (n + b)) depends on the number of digits d. The larger the integers, the larger d is, and the advantage over Quick Sort shrinks.
- Radix Sort cannot take advantage of data that already has some order, so on already sorted data it is slower than Quick Sort.
**Difficulties and how I handled them:**
 
- Telling theoretical complexity apart from real running time: I compared the measured numbers with the theory to explain why the two differ.
**AI usage:** Used Claude to suggest test sets (weeks 1, 3 and 4).
## Joint work
 
- Chose one hand-calculated example and compared it with the program's output (`docs/week3/hand-calculated.md`).
- Agreed on a shared set of test data for both comparisons.
