#include <bits/stdc++.h>

using namespace std;

int n, k;
const int N = 6000;

long long C[N], D[N];
vector<int> Adj[N];
vector<pair<int, int>> new_Adj[N];

bool is_visited[N];
int dist[N][N];

bool is_used[N];
const int INF = INT_MAX;
vector<int> Dist(N, INF);

int Bellman_Ford(int start, int end){
    Dist[start] = 0;

    for (int u = 1; u<= n; u++){
        for (int j = 0; j< new_Adj[u].size(); j++){
            int v = new_Adj[u][j].first;
            int w = new_Adj[u][j].second;
            Dist[v] = min(Dist[v], Dist[u] + w);
        }
    }


    return Dist[end];
}

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
            int v = new_Adj[u][i].first;

            int w = new_Adj[u][i].second;

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

int find_mpath(int start, int end){
    queue<pair<int,int>> Q;
    is_visited[start] = true;
    Q.push({start, 0});
    
    while(!Q.empty()){
        int u = Q.front().first;
        int d = Q.front().second;
        Q.pop();
        if (u == end){
            return d;
        }
        for (int i = 0; i< Adj[u].size(); i++){

            int v = Adj[u][i];
            if (!is_visited[v]){
                is_visited[v] = true;
                Q.push(make_pair(v, d+1));
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i<= n; i++){
        cin >> C[i] >> D[i];
    }
    for (int i = 1; i<= k; i++){
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i<= n; i++){
        for (int j = 1; j <= n; j++){
            if (dist[i][j] != -1) continue;
            memset(is_visited, false, sizeof(is_visited));
            dist[i][j] = find_mpath(i, j);
            dist[j][i] = dist[i][j];
        }
    }

    for (int i = 1; i<= n; i++){
        vector<pair<int, int>> temp;
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            temp.push_back({dist[i][j], j});
        }
        sort(temp.begin(), temp.end(), [](const pair<int, int>a, const pair<int, int> b){return a.first > b.first;});
        for (auto p: temp){
            if (D[i] >= p.first){
                new_Adj[i].push_back({p.second, C[i]});
            }
        }

    }

    memset(is_used, false, sizeof(is_used));
    cout << Dijkstra(1, n) << endl;


    return 0;
}