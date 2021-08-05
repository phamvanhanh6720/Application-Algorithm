#include <bits/stdc++.h>

using namespace std;

const int N = 21;
long long C[N][N];
int n, m;

int mark[N];
int use[N];
long long best_cost = 1e6;
long long curr_cost = 0;
long long min_value = 1e6;

void TRY(int k)
{
    if (k > n)
    {
        if (C[use[n]][1])
        {
            best_cost = min(best_cost, curr_cost + C[use[n]][1]);
        }
        return;
    }

    int pre_location = use[k - 1];
    for (int i = 2; i <= n; i++)
    {
        if (!mark[i] && C[pre_location][i])
        {
            use[k] = i;
            curr_cost += C[pre_location][i];
            mark[i] = 1;

            if (curr_cost + (n - k + 1) * min_value < best_cost)
                TRY(k + 1);

            mark[i] = 0;
            curr_cost -= C[pre_location][i];
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        long long u, v, c;
        cin >> u >> v >> c;
        C[u][v] = c;
        min_value = min(min_value, c);
    }
    use[1] = 1;
    mark[1] = 1;
    TRY(2);
    cout << best_cost << endl;

    return 0;
}