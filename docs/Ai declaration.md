# Khai báo sử dụng AI - Tuần 1

Người thực hiện: Nguyễn Võ Hoàng Huy (25110023)
## 1.AI

| Mục | Nội dung |
|-----|----------|
| Công cụ | Claude, phiên bản Sonnet 5.5 |
| Mục đích | Liệt kê các trường hợp biên và sinh bộ test cho thuật toán Counting Sort |

## 2. Prompt đã dùng

> Hãy in ra các trường hợp biên và bộ test cho thuật toán này

## 3. AI tạo ra

AI sinh ra các bộ test cho Counting Sort, chia theo bốn nhóm:

- Ví dụ bình thường.
- Trường hợp biên: mảng rỗng, 1 phần tử, toàn giá trị trùng nhau, đã sắp xếp tăng, sắp xếp giảm, giá trị 0 và 1.000.000.
- Đầu vào sai: số âm, giá trị vượt quá 1.000.000, số phần tử âm.
- Input lớn: n = 1.000.000, giá trị ngẫu nhiên trong [0, 1000].

## 4. Sinh viên đã chỉnh sửa

Chạy `counting_sort.cpp` với các bộ test trên và đối chiếu kết quả thực tế với kết quả mong đợi.
## 5. Kết quả kiểm thử
Đúng với kết quả mong đợi
## 6. Liên kết minh chứng

- Code: [counting_sort.cpp](https://github.com/nguyenvohoanghuy31/Project-DSA--NguyenVoHoangHuy_25110023-LeMinhDuy_25110010/blob/main/counting_sort.cpp)
- Bộ test: [thư mục Tests](https://github.com/nguyenvohoanghuy31/Project-DSA--NguyenVoHoangHuy_25110023-LeMinhDuy_25110010/tree/main/Tests)
