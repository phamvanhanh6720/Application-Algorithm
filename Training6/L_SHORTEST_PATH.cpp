#include <bits/stdc++.h>

using namespace std;
int n, m;
int s, t;

const int N = 1e5 + 10;
vector<pair<int, int>> Adj[N];
bool is_used[N];
const int INF = INT_MAX;
vector<int> Dist(N, INF);

int Dijkstra(int start, int end)
{
    Dist[start] = 0;
    priority_queue<pair<int, int>> PQ;

    PQ.push(make_pair(Dist[start], start));

    while (!PQ.empty())
    {
        int u = PQ.top().second;
        PQ.pop();
        if (is_used[u]) continue;
        is_used[u] = true;

        for (int i = 0; i < Adj[u].size(); i++)
        {
            int v = Adj[u][i].first;

            int w = Adj[u][i].second;

            if (w + Dist[u] < Dist[v])
            {
                Dist[v] = w + Dist[u];
                PQ.push(make_pair(-Dist[v], v));
            }
        }
    }
    if (is_used[end]){
        return Dist[end];
    }
    else{
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Adj[u].push_back({v, w});
    }
    cin >> s >> t;
    cout << Dijkstra(s, t) << endl;

    return 0;
}