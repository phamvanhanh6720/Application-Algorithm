#include <bits/stdc++.h>

using namespace std;
int n, m; //n: n coures, m: m periods
const int N = 20;
bool A[N][N];
int credit[N] = {0};
int load[N] = {0}; // load of each periods
int course[N] = {0};

int max_credit = INT_MAX;
int kq = INT_MAX;

bool accept(int i, int u)
{
    // i: period, u: course
    for (int j = 1; j < u; j++)
    {
        if (A[j][u])
        {
            if (course[j] >= i)
                return false;
        }
        if (A[u][j])
        {
            if (course[j] <= i)
                return false;
        }
        return true;
    }
}

void TRY(int u)
{
    if (u > n)
    {
        int max_load = 0;
        for (int i = 1; i <= m; i++)
        {
            max_load = max(max_load, load[i]);
        }
        kq = min(max_load, kq);
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (accept(i, u))
        {
            course[u] = i;
            load[i] += credit[u];
            if (load[i] < kq)
                TRY(u + 1);
            course[u] = 0;
            load[i] -= credit[u];
        }
    }
}

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> credit[i];
        max_credit = max(max_credit, credit[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }
}

int main()
{
    input();
    TRY(1);
    cout << kq << endl;
    return 0;
}