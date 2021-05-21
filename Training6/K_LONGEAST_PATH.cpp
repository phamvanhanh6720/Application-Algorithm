
#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 1e5 + 10;
vector<pair<int,int>> Adj[N];

int min_length;

void Bellman_Ford(int start, int n){
    vector<int> Dist(N, INT_MAX);
    Dist[start] = 0;
    for (int u = 1; u<=n; u++){
        for (int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].first;
            int w = Adj[u][j].second;
            
            Dist[v] = min(Dist[v], Dist[u] + w);

            min_length = min(min_length, Dist[v]);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Adj[u].push_back({v, -w});
        Adj[v].push_back({u, -w});
    }
    min_length = 0;
    for (int start = 1; start <= n; start++){
        Bellman_Ford(start, n);
    }
    cout << -min_length<< endl;

    return 0;
}