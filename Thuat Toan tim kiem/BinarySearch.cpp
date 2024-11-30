#include <bits/stdc++.h>
using namespace std;
// 1 3 4 5 7 8 9 10 15 23 tim vi tri cua so 5
// 1 2 3 4 5 6 7 8 9 10
int main()
{
    int n, s = 0;
    cin >> n;
    int a[n]; // 0 -> n
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; // start 1
    }
    int left = 1, right = n;
    int x = 5;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] < x)
        { // mid < right 2 3
            left = mid + 1;
        }
        if (a[mid] > x)
        {
            right = mid - 1;
        }
        if (a[mid] == x)
        {
            cout << mid << "\n";
            break;
        }
    } // return : dung chuong trinh; break: thoat khoi ham dieu kien/vong lap
    cout << "hello world";
}