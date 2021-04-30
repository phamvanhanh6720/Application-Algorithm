#include <bits/stdc++.h>

using namespace std;
int n, k, m;
const int N = 1e5 + 10;
vector<vector<pair<int, int>>> A(N);
int res = INT_MAX;

void dfs(int u, int p, int sum, int depth)
{
    if (depth == k)
    {
        res = min(sum, res);
        return;
    }
    else
    {
        for (int i = 0; i < A[u].size(); i++)
        {
            int v = A[u][i].first;
            int w = A[u][i].second;
            if (v == p)
            {
                continue;
            }
            dfs(v, u, sum + w, depth + 1);
        }
    }
}

int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back({v, w});
        A[v].push_back({u, w});
    }
    for (int i = 1; i <= m; i++)
    {
        dfs(i, 0, 0, 0);
    }
    cout << res << endl;

    return 0;
}