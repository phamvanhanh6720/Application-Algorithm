#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
vector<int> Adj[N];
int n, m;
vector<int> Low(N), Num(N, -1);
bool is_visited[N];
bool is_artic[N];
int root, n_child;
int n_bridges = 0;
int cnt;

void dfs(int u, int p)
{
    is_visited[u] = true;
    Num[u] = Low[u] = cnt++;
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if (v == p)
            continue;
        if (is_visited[v])
        {
            Low[u] = min(Low[u], Num[v]);
        }
        else
        {
            dfs(v, u);
            Low[u] = min(Low[u], Low[v]);
            if (root == u)
            {
                n_child++;
            }
            if (Low[v] >= Num[u])
            {
                is_artic[u] = 1;
            }
        }
        if (Low[v] > Num[u])
        {
            n_bridges++;
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
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!is_visited[i])
        {
            root = i;
            n_child = 0;
            dfs(i, -1);
            is_artic[i] = n_child > 1;
        }
    }
    int num_artic = 0;
    for (int i = 1; i <= n; i++)
    {
        num_artic += is_artic[i];
    }
    cout << num_artic << ' ' << n_bridges << endl;
    return 0;
}