# So sánh Radix Sort và Quick Sort

## 1. So sánh lý thuyết

| Tiêu chí              | Radix Sort (LSD, cơ số 10)                           | Quick Sort                                                            |
| --------------------- | ---------------------------------------------------- | --------------------------------------------------------------------- |
| Loại                  | Không so sánh                                        | So sánh                                                               |
| Độ phức tạp thời gian | O(d · (n + 10)), d là số chữ số của giá trị lớn nhất | Trung bình O(n log n), xấu nhất O(n²)                                 |
| Bộ nhớ thêm           | O(n + 10)                                            | Trung bình O(log n) cho ngăn xếp đệ quy; xấu nhất O(n) với pivot giữa |
| Ổn định               | Có                                                   | Không (bản đổi chỗ tại chỗ)                                           |
| Điều kiện dữ liệu     | Số nguyên không âm                                   | Bất kỳ kiểu nào so sánh được                                          |

## 2. Kết quả thực nghiệm

**Cách đo.** Mỗi thuật toán sắp một bản sao của cùng một dữ liệu, lấy thời gian nhỏ nhất trong 3 lần chạy. Chỉ đo thời gian sắp xếp.

### 2.1. Dữ liệu ngẫu nhiên

| Kịch bản                                 | n   | Số chữ số d | Radix (ms) | Quick (ms) |
| ---------------------------------------- | --- | ----------- | ---------- | ---------- |
| a. khoảng nhỏ 0–99                       | 10⁶ | 2           | 7.03       | 35.38      |
| a2. khoảng vừa 0–10⁶                     | 10⁶ | 7           | 20.25      | 82.04      |
| b. 100 giá trị khác nhau, khoảng 0–2·10⁹ | 10⁶ | 10          | 41.89      | 33.90      |
| c. ngẫu nhiên đều 0–2·10⁹                | 10⁶ | 10          | 39.92      | 83.21      |
| a. khoảng nhỏ 0–99                       | 10⁷ | 2           | 163.44     | 368.13     |
| a2. khoảng vừa 0–10⁶                     | 10⁷ | 7           | 508.82     | 859.05     |
| b. 100 giá trị khác nhau, khoảng 0–2·10⁹ | 10⁷ | 10          | 963.07     | 372.37     |
| c. ngẫu nhiên đều 0–2·10⁹                | 10⁷ | 10          | 993.99     | 957.90     |

### 2.2. Các trường hợp biên và dữ liệu đặc biệt

| STT | Trường hợp                                           | n   | Radix (ms)  | Quick (ms) | Kết quả đúng |
| --- | ---------------------------------------------------- | --- | ----------- | ---------- | ------------ |
| 1   | Mảng rỗng                                            | 0   | lỗi (crash) | ≈ 0        | Chỉ Quick    |
| 2   | Mảng 1 phần tử                                       | 1   | ≈ 0         | ≈ 0        | Có           |
| 3   | Tất cả giá trị giống nhau                            | 10⁶ | 35.28       | 13.24      | Có           |
| 4   | Đã sắp tăng dần                                      | 10⁶ | 27.43       | 7.73       | Có           |
| 5   | Sắp giảm dần                                         | 10⁶ | 26.68       | 7.59       | Có           |
| 6   | Chỉ có hai giá trị biên 0 và 1.000.000               | 10⁶ | 38.60       | 21.47      | Có           |
| 7   | Giá trị có số chữ số khác nhau (5, 42, 802, 1000000) | 10⁶ | 35.40       | 19.66      | Có           |
| 3   | Tất cả giá trị giống nhau                            | 10⁷ | 596.98      | 179.54     | Có           |
| 4   | Đã sắp tăng dần                                      | 10⁷ | 561.75      | 150.66     | Có           |
| 5   | Sắp giảm dần                                         | 10⁷ | 600.25      | 113.83     | Có           |
| 6   | Chỉ có hai giá trị biên 0 và 1.000.000               | 10⁷ | 698.44      | 173.20     | Có           |
| 7   | Giá trị có số chữ số khác nhau (5, 42, 802, 1000000) | 10⁷ | 573.84      | 215.95     | Có           |

## 3. Nhận xét

- Với dữ liệu ngẫu nhiên, Radix Sort nhanh hơn Quick Sort khi số chữ số d nhỏ: khoảng 5 lần (d = 2), 2–4 lần (d = 7). Khi d = 10 (kịch bản c), lợi thế gần như mất ở n = 10⁷ (994 ms so với 958 ms).
- Quick Sort nhanh hơn rõ ở kịch bản b (nhiều giá trị trùng, chỉ 100 giá trị khác nhau): khoảng 1.2 lần ở n = 10⁶ và 2.6 lần ở n = 10⁷. Radix Sort không tận dụng được việc trùng giá trị.
- Với dữ liệu đặc biệt (2.2), Quick Sort nhanh hơn Radix Sort khoảng 2–5 lần: mảng đã sắp, sắp ngược và toàn giá trị giống nhau là trường hợp dễ cho Quick Sort (pivot giữa, không suy biến về O(n²)), nhưng Radix Sort vẫn phải chạy đủ d lượt.
- Radix Sort đòi hỏi dữ liệu là số nguyên không âm, và cài đặt này lỗi với mảng rỗng, trong khi Quick Sort xử lý đúng mọi trường hợp biên.

## 4. Lựa chọn thuật toán

| Tình huống                                                     | Nên dùng                               |
| -------------------------------------------------------------- | -------------------------------------- |
| Số nguyên không âm, số chữ số ít (mã, điểm số, tuổi, ID ngắn)  | Radix Sort                             |
| Số nguyên rất lớn (nhiều chữ số) hoặc có nhiều giá trị trùng   | Quick Sort                             |
| Dữ liệu không phải số nguyên (chuỗi dài không đều, đối tượng)  | Quick Sort                             |
| Cần giữ thứ tự của các phần tử bằng nhau                       | Radix Sort (hoặc sắp xếp ổn định khác) |
| Dữ liệu đã sắp hoặc gần sắp, mảng rất nhỏ, hoặc bộ nhớ hạn chế | Quick Sort                             |
