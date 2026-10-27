#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& a, int l, int r) {
    int p = a[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}

void QuickSort(vector<int>& a) {
    if (a.size() < 2) return;
    QuickSort(a, 0, (int)a.size() - 1);
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin>>n;
    vector<int> mang(n);
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cin>>mang[i];
    }
    QuickSort(mang);
    cout << "Mang sau khi sap xep: ";
    for (int x : mang)
        cout << x << " ";
    cout << endl;
    return 0;
}