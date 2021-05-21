#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
int n, k;
int c[N], d[N];
vector<int> Adj[N];
int dist[N][N];
int used[N];
int min_dist[N];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for (int i=1; i<=n; i++){
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= k; i++){
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    for (int i = 1; i<=n; i++){
        fill(used + 1, used + n + 1, 0);
        queue<int> q;
        q.push(i);
        used[i] = 1;
        dist[i][i] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for (int v: Adj[u]){
                if (used[v]) continue;
                used[v] = 1;
                q.push(v);
                dist[i][v] = dist[i][u] + 1;

            }
        }
    }
    fill(used + 1, used + n + 1, 0);
    fill(min_dist, min_dist + n + 1, INT_MAX);
    min_dist[1] = 0;
    while(true){
        int min_node = -1;
        for(int i = 1; i <= n; i++){
            if (used[i]) continue;
            if (min_node == -1 || min_dist[min_node] > min_dist[i]){
                min_node = i;
            }
            
        }
        if (min_node == -1) break;
        used[min_node] = 1;
        for (int i = 1; i<=n; i++){
            if (dist[min_node][i] <= d[min_node]){
                min_dist[i] = min(min_dist[i], min_dist[min_node] + c[min_node]);
            }
        }
    }
    cout << min_dist[n] << endl;

    return 0;
}