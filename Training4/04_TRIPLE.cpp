#include <bits/stdc++.h>

using namespace std;
int n;
long long k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<long long> a(n);
    for (long long &value : a)
    {
        cin >> value;
    }
    sort(a.begin(), a.end());
    int res = 0;

    for (int x = 0; x < a.size() - 2; x++)
    {
        for (int y = x + 1; y < a.size() - 1; y++)
        {
            long long value = (k - a[x] -a[y]);
            if (value < a[y]) continue;

            if (binary_search(a.begin()+(y+1), a.end(), value)){
                res += 1;
            }
        }
    }
    cout << res << endl;

    return 0;
}