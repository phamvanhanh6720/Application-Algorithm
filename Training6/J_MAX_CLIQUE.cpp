#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 20;
int Adj[N][N];
int deg[N];
vector<int> order_deg;
vector<int> res;

int main(){
    cin >> n >> m;
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i<= m; i++){
        int u, v;
        cin >> u >> v;
        Adj[u][v] = 1;
        deg[u] += 1;
        Adj[v][u] = 1;
        deg[v] += 1;
    }

    for (int i = 1; i <= n; i++){
        order_deg.push_back(i);
    }
    sort(order_deg.begin(), order_deg.end(), [](int u, int v){ return deg[u] > deg[v];});

    for (int i = 0; i < order_deg.size(); i++){
        int u = order_deg[i];
        int flag = false;

        for (int v: res){
            if (!Adj[u][v]){
                flag =true;
                break;
            }
        }
        if (!flag){
            res.push_back(u);
        }
    }
    cout << res.size() << endl;

    return 0;
}