#include <iostream>
#include <vector>
using namespace std;

void Radixsort(vector<int>& mang) {
    int lonNhat = mang[0];
    for (int x : mang)
        if (x > lonNhat) lonNhat = x;
    for (int hang = 1; lonNhat / hang > 0; hang *= 10) {
        vector<int> thung[10];
        for (int x : mang) {
            int chuSo = (x / hang) % 10;
            thung[chuSo].push_back(x);
        }
        int viTri = 0;
        for (int d = 0; d < 10; d++)
            for (int x : thung[d])
                mang[viTri++] = x;
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    vector<int> mang(n);
    cout << "Nhap " << n << " so nguyen khong am: ";
    for (int i = 0; i < n; i++)
        cin >> mang[i];
    Radixsort(mang);
    cout << "Mang sau khi sap xep: ";
    for (int x : mang)
        cout << x << " ";
    cout << endl;
    return 0;
}