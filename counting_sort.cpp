#include <bits/stdc++.h>
using namespace std;

#define MAX_LENGTH 1000000
#define MAX_ELEMENT 1000000

int a[MAX_LENGTH];
int cnt[MAX_ELEMENT + 1];

int main()
{
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap " << n << " so nguyen (tu 0 den " << MAX_ELEMENT << "): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0 || a[i] > MAX_ELEMENT) {
            cout << "Gia tri " << a[i] << " nam ngoai khoang [0, " << MAX_ELEMENT << "]" << endl;
            return 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    for (int i = 0, j = 0; j <= MAX_ELEMENT; j++)
    {
        while (cnt[j] > 0)
        {
            cnt[j]--;
            a[i++] = j;
        }
    }

    cout << "Sau khi sap xep: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    } 
    cout << endl;
    return 0;
}