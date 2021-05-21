#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int n;
    cin >> n;
    n = 1000 - n;
    int a[6] = {1, 5, 10, 50, 100, 500};
    int res = 0;
    for (int i = 5; i >= 0; i--)
    {
        res += n / a[i];
        n %= a[i];
    }
    cout << res << endl;
}