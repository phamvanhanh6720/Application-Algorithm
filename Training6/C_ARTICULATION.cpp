#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
vector<int> Adj[N];
int n, m;
vector<int> iComponent[N];
vector<int> Low(N), Num(N, -1);

int n_bridges = 0;
void analyze_dfs(int u, int p)
{
    Low[u] = Num[u] = ++n_bridges;

    for (int i = 0; i <= Adj[i].size(); i++)
    {
        int v = Adj[u][i];
        if (v == p)
            continue;
        if (Num[v] == -1)
        {
            analyze_dfs(v, u);
            Low[u] = min(Low[u], Low[v]);
        }
        else
        {
            Low[u] = min(Low[u], Num[v]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    n_bridges = 0;
    for (int i = 1; i<= n;i++){
        
    }
    return 0;
}