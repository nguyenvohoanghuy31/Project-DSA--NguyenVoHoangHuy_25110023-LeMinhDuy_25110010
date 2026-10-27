# Khai báo sử dụng AI - Tuần 3

## 1. AI

| Mục | Nội dung |
|---|---|
| Công cụ | Claude, phiên bản Sonnet 5.5 |
| Mục đích | Sinh các bộ test thực tế để so sánh Counting Sort với Quick Sort và Radix Sort với Quick Sort |

## 2. Prompt đã dùng

> Hãy sinh các bộ dữ liệu test thực tế để so sánh thời gian chạy của Counting Sort, Radix Sort với Quick Sort.

## 3. AI tạo ra

AI đề xuất các bộ dữ liệu để đo thời gian, chia theo các nhóm:

- Kích thước tăng dần: n = 1.000, 10.000, 100.000, 1.000.000.
- Dạng dữ liệu: ngẫu nhiên, đã sắp xếp tăng, sắp xếp giảm, nhiều phần tử trùng nhau.

## 4. Sinh viên đã chỉnh sửa

- Chọn lại các giá trị n và k cho phù hợp với giới hạn của chương trình và thời gian chạy trên máy.
- Cố định dữ liệu để cả hai thuật toán trong mỗi phép so sánh chạy trên cùng một bộ test.
- Chạy nhiều lần, lấy kết quả trung bình rồi ghi vào bảng số liệu.

## 5. Kết quả kiểm thử

Các bộ test chạy đúng, kết quả sắp xếp của các thuật toán khớp nhau. Số liệu thời gian được ghi trong các file so sánh ở `docs/week3`.

## 6. Liên kết minh chứng

- Code: [counting_sort.cpp](counting_sort.cpp), [Radixsort.cpp](Radixsort.cpp)
- Kết quả so sánh: [Counting Sort vs Quick Sort](docs/week3/Compare-coutingsort_vs_quicksort.md), [Radix Sort vs Quick Sort](docs/week3/Compare-radixsort_vs_quicksort.md)
