#include <bits/stdc++.h>

using namespace std;

struct Rec
{
    int x, y, z;
};
int n;
int m;
const int N = 500;
Rec block[N];
int dp[N];
const int INF = INT_MAX;

bool compare(const Rec a, const Rec b)
{
    if (a.x != b.x)
        return a.x > b.x;
    if (a.y != b.y)
        return a.y > b.y;

    return a.z > b.z;
}

int main()
{   ios_base::sync_with_stdio(0); cin.tie(0);
    int count = 1;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        m = 0;
        memset(dp, 0, sizeof(dp));
        block[0].x = INF;
        block[0].y = INF;
        block[0].z = 0;

        for (int i = 1; i <= n; i++)
        {
            int a[3];
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a + 3);
            do
            {
                block[++m].x = a[0];
                block[m].y = a[1];
                block[m].z = a[2];
            } while (next_permutation(a, a + 3));
        }
        int ans = 0;
        sort(block + 1, block + m + 1, compare);
        //cout << m << "--" << endl;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (block[j].x > block[i].x && block[j].y > block[i].y)
                {
                    dp[i] = max(dp[i], dp[j] + block[i].z);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << "Case " << count << ": maximum height = " << ans << endl;
        count++;
    }

    return 0;
}