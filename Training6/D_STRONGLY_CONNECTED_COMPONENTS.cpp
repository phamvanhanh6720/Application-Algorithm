#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1e5 + 10;
vector<int> adj[N];
bool is_connected[N];
bool is_visited[N];

int low[N], num[N];
stack<int> comp;
int n_component;
int cnt;

void dfs(int u)
{
    comp.push(u);
    is_connected[u] = true;
    is_visited[u] = true;
    low[u] = num[u] = cnt++;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!is_visited[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(is_connected[v]){
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]){
        n_component++;
        while(true){
            int v = comp.top();
            comp.pop();
            is_connected[v] = false;
            if (v == u) break;
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
    }
    n_component = 0;
    cnt = 0;
    memset(is_visited, false, sizeof(is_connected));

    for (int i = 1; i <= n; i++)
    {
        if (!is_visited[i])
        {
            dfs(i);
        }
    }
    cout << n_component << endl;

    return 0;
}