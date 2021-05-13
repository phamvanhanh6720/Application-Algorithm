#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1000;
const long long M = (1e9 + 7);
int a[N];
long long dp[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= m; j++)
        {
            for (int k = j - a[i]; k >= 0; k -= a[i])
            {
                dp[i][j] += (dp[i - 1][k]);
                dp[i][j] %= M;
            }
        }
    }
    cout << dp[n][m]<< endl;

    return 0;
}