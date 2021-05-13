#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
bool is_visited[N];
bool color[N];
int n, m;
bool is_cololable;

void dfs(int u)
{
    is_visited[u] = 1;
    for (auto v : adj[u])
    {
        if (is_visited[v])
        {
            if (color[u] == color[v])
            {
                is_cololable = false;
                return;
            }
        }
        else
        {
            color[v] = !color[u];
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    is_cololable = true;
    for (int i = 1; i <= n; i++)
    {
        if (!is_visited[i])
        {
            color[i] = 1;
            dfs(i);

        }
    }
    cout << is_cololable << endl;
}