#include<bits/stdc++.h>

using namespace std;
int n_test;

const int N = 2010;
vector<int> adj[N];
bool is_visited[N];
bool color[N];
int n, m;
bool is_accept;

void dfs(int u){
    is_visited[u] = true;
    for (auto v: adj[u]){
        if (is_visited[v]){
            if (color[v] == color[u]){
                is_accept = false;
                return;
            }
        }
        else{
            color[v] = !color[u];
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n_test;
    int ori_test = n_test;

    while (n_test--)
    { 
        memset(adj, 0, sizeof(adj));
        memset(color, -1, sizeof(color));
        memset(is_visited, false, sizeof(is_visited));
        is_accept = true;
        cin >> n >> m;
        for (int i = 1; i<= m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i<= n; i++){
            if (!is_visited[i]){
                color[i] = 1;
                dfs(i);
                if (!is_accept){
                    break;
                }
            }
        }

        cout << "Scenario #" << (ori_test - n_test) << ":" << endl;
        if (is_accept){
            cout << "No suspicious bugs found!" << endl;
        }
        else{
            cout << "Suspicious bugs found!" << endl;
        }
    }
    

    return 0;
}