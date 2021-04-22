#include <bits/stdc++.h>

using namespace std;
int n, T, D;
const int N = 2000;
int a[N];
int t[N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = 0;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int k = t[i]; k <= T; k++)
        {
            for (int j = i - 1; j >= max(0, i - D); j--)
            {
                dp[i][k] = max(dp[i][k], dp[j][k - t[i]] + a[i]);
            }
            res = max(res, dp[i][k]);
        }
    }
    cout << res << endl;

    return 0;
}