# So sánh Counting Sort và Quick Sort

## 1. So sánh lý thuyết

| Tiêu chí              | Counting Sort                         | Quick Sort                                                            |
| --------------------- | ------------------------------------- | --------------------------------------------------------------------- |
| Loại                  | Không so sánh (phân phối)             | So sánh                                                               |
| Độ phức tạp thời gian | O(n + k)                              | Trung bình O(n log n), xấu nhất O(n²)                                 |
| Bộ nhớ thêm           | O(n + k)                              | Trung bình O(log n) cho ngăn xếp đệ quy; xấu nhất O(n) với pivot giữa |
| Ổn định               | Có (nếu duyệt ngược khi đặt vào)      | Không (bản đổi chỗ tại chỗ)                                           |
| Điều kiện dữ liệu     | Số nguyên trong khoảng [0, k] đã biết | Bất kỳ kiểu nào so sánh được                                          |

## 2. Kết quả thực nghiệm

**Cách đo.** Mỗi thuật toán sắp một bản sao của cùng một dữ liệu, lấy thời gian nhỏ nhất trong 3 lần chạy. Chỉ đo thời gian sắp xếp.

### 2.1. Dữ liệu ngẫu nhiên

| Kịch bản                                 | n   | k (khoảng giá trị) | Counting (ms)             | Quick (ms) |
| ---------------------------------------- | --- | ------------------ | ------------------------- | ---------- |
| a. khoảng nhỏ 0–99                       | 10⁶ | 99                 | 1.04                      | 36.00      |
| a2. khoảng vừa 0–10⁶                     | 10⁶ | 10⁶                | 12.07                     | 84.43      |
| b. 100 giá trị khác nhau, khoảng 0–2·10⁹ | 10⁶ | 2·10⁹              | không chạy được (k > 10⁶) | 42.21      |
| c. ngẫu nhiên đều 0–2·10⁹                | 10⁶ | 2·10⁹              | không chạy được (k > 10⁶) | 93.90      |
| a. khoảng nhỏ 0–99                       | 10⁷ | 99                 | không chạy được (n > 10⁶) | 362.53     |
| a2. khoảng vừa 0–10⁶                     | 10⁷ | 10⁶                | không chạy được (n > 10⁶) | 935.83     |
| b. 100 giá trị khác nhau, khoảng 0–2·10⁹ | 10⁷ | 2·10⁹              | không chạy được (n > 10⁶) | 398.49     |
| c. ngẫu nhiên đều 0–2·10⁹                | 10⁷ | 2·10⁹              | không chạy được (n > 10⁶) | 1017.43    |

### 2.2. Các trường hợp biên và dữ liệu đặc biệt

| STT | Trường hợp                                           | n   | Counting (ms)             | Quick (ms) | Kết quả đúng |
| --- | ---------------------------------------------------- | --- | ------------------------- | ---------- | ------------ |
| 1   | Mảng rỗng                                            | 0   | 0.36                      | ≈ 0        | Có           |
| 2   | Mảng 1 phần tử                                       | 1   | 0.35                      | ≈ 0        | Có           |
| 3   | Tất cả giá trị giống nhau                            | 10⁶ | 3.12                      | 12.64      | Có           |
| 4   | Đã sắp tăng dần                                      | 10⁶ | 1.68                      | 7.38       | Có           |
| 5   | Sắp giảm dần                                         | 10⁶ | 1.78                      | 6.92       | Có           |
| 6   | Chỉ có hai giá trị biên 0 và 1.000.000               | 10⁶ | 2.27                      | 15.12      | Có           |
| 7   | Giá trị có số chữ số khác nhau (5, 42, 802, 1000000) | 10⁶ | 1.57                      | 20.97      | Có           |
| 3   | Tất cả giá trị giống nhau                            | 10⁷ | không chạy được (n > 10⁶) | 145.91     | Có           |
| 4   | Đã sắp tăng dần                                      | 10⁷ | không chạy được (n > 10⁶) | 120.69     | Có           |
| 5   | Sắp giảm dần                                         | 10⁷ | không chạy được (n > 10⁶) | 123.70     | Có           |
| 6   | Chỉ có hai giá trị biên 0 và 1.000.000               | 10⁷ | không chạy được (n > 10⁶) | 191.60     | Có           |
| 7   | Giá trị có số chữ số khác nhau (5, 42, 802, 1000000) | 10⁷ | không chạy được (n > 10⁶) | 235.12     | Có           |

## 3. Nhận xét

- Khi n = 10⁶, Counting Sort nhanh hơn Quick Sort khoảng 35 lần (k = 99) và khoảng 7 lần (k = 10⁶). Khoảng giá trị k càng lớn thì hiệu suất càng giảm.
- Ở n = 10⁷, Counting Sort không chạy được do giới hạn `MAX_LENGTH` của cài đặt, còn Quick Sort chạy được ở mọi kịch bản.
- Quick Sort không suy biến về O(n²) với dữ liệu đã sắp, sắp ngược hoặc toàn giá trị giống nhau. Counting Sort vẫn nhanh hơn khoảng 4–13 lần và gần như không phụ thuộc thứ tự dữ liệu.
- Với mảng rỗng hoặc 1 phần tử, cả hai đều đúng, nhưng Counting Sort vẫn tốn khoảng 0.35 ms do luôn quét toàn bộ mảng đếm.

## 4. Lựa chọn thuật toán

| Tình huống                                                       | Nên dùng                                  |
| ---------------------------------------------------------------- | ----------------------------------------- |
| Số nguyên, khoảng giá trị nhỏ và đã biết (điểm số, tuổi, mã nhỏ) | Counting Sort                             |
| Khoảng giá trị rất lớn hoặc không biết trước                     | Quick Sort                                |
| Dữ liệu không phải số nguyên (chuỗi, đối tượng)                  | Quick Sort                                |
| Cần giữ thứ tự của các phần tử bằng nhau                         | Counting Sort (hoặc sắp xếp ổn định khác) |
| Bộ nhớ hạn chế, hoặc n vượt giới hạn mảng của cài đặt            | Quick Sort                                |
