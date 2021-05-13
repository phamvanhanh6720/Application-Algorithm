#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
vector<int> Adj[N];
bool visisted[N];
int n,m;

void dfs(int u)
{
    visisted[u] = true;
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if (!visisted[v])
        {
            dfs(v);
        }
    }
}

int main()
{   memset(visisted, false, sizeof(visisted));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visisted[i])
        {
            dfs(i);
            res++;
        }
    }
    cout << res << endl;

    return 0;
}