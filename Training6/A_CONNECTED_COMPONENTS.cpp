#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
vector<int> Adj[N];
vector<int> iComponent(N, -1);
int n, m;

void Find_Component(int cur_comp, int u)
{
    if (iComponent[u] != -1)
        return;

    iComponent[u] = cur_comp;

    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        Find_Component(cur_comp, v);
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
    int res = 0;
    for (int i =1; i<=n; i++){
        if (iComponent[i] == -1){
            Find_Component(res, i);
            res++;
        }
    }
    cout << res << endl;

    return 0;
}