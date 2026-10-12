# Báo cáo tuần 1: Counting Sort

## 1. Thuật toán

Code Counting Sort dùng một mảng đếm `cnt`, trong đó **chỉ số là giá trị phần tử**.

Các bước thực hiện:

1. Đếm số lần xuất hiện của từng giá trị trong mảng đầu vào.
2. Duyệt các giá trị từ nhỏ đến lớn.
3. Ghi lại từng giá trị vào mảng kết quả theo đúng số lần đã đếm.

## 2. Độ phức tạp

| Tiêu chí  | Giá trị  |
| --------- | -------- |
| Thời gian | O(n + k) |

Trong đó `n` là số phần tử của mảng và `k` là khoảng giá trị của phần tử (kích thước mảng đếm `cnt`).

## 3. Test

### 3.1. Ví dụ bình thường

Mảng có nhiều giá trị khác nhau, có thể trùng nhau, được sắp xếp tăng dần đúng kết quả.

### 3.2. Trường hợp biên

| STT | Trường hợp                 |
| --- | -------------------------- |
| 1   | Mảng rỗng                  |
| 2   | Mảng có 1 phần tử          |
| 3   | Toàn bộ giá trị trùng nhau |
| 4   | Mảng đã sắp xếp tăng       |
| 5   | Mảng sắp xếp giảm          |
| 6   | Giá trị 0 và 1.000.000     |

### 3.3. Đầu vào sai

| STT | Trường hợp                 |
| --- | -------------------------- |
| 1   | Số âm                      |
| 2   | Giá trị vượt quá 1.000.000 |
| 3   | Số phần tử âm              |

### 3.4. Input lớn

- `n = 1.000.000`
- Giá trị ngẫu nhiên trong khoảng `[0, 1000]`
