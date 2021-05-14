#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 1e5 + 10;
vector<vector<pair<int, int>>> adj;
int weight;
int res;
bool is_visited[N];
bool is_leave[N];

void dfs(int u)
{
    is_visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        if (!is_visited[v]){
            weight += w;
            if (is_leave[v]){
                is_visited[v] = true;
                res = max(res, weight);
            }
            else{
                dfs(v);
            }
            weight -= w;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj = vector<vector<pair<int, int>>>(n + 1);
    memset(is_leave, false, sizeof(is_leave));

    for (int i = 1; i <= (n - 1); i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= n; i++){
        if (adj[i].size() == 1){
            is_leave[i] = true;
        }
    }
    res = 0;

    for (int i = 1; i <= n; i++)
    {
        weight = 0;
        memset(is_visited, 0, sizeof(is_visited));
        dfs(i);
    }
    cout << res << endl;
    return 0;
}