#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e6 + 1;
int a[N];
long long pre_sum[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pre_sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }

    long long res = -1e15;
    long long min_odd = (long long)1e15 + 1;
    long long min_even = (long long)1e15;

    for (int i = 1; i <= n; i++)
    {
        long long sum = pre_sum[i];
        if (sum % 2)
        {
            sum -= min_odd;
        }
        else
        {
            sum -= min_even;
        }
        res = max(res, sum);
        if (pre_sum[i] % 2)
        {
            min_odd = min(min_odd, pre_sum[i]);
        }
        else
        {
            min_even = min(min_even, pre_sum[i]);
        }
    }
    cout << res << endl;

    return 0;
}