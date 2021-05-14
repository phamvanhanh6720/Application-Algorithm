#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e5+10;
vector<int> adj[N];

int main(){
    cin >> n;
    for (int i = 1; i<=(n-1); i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count = 0;
    for (int i = 2; i<=n; i++){
        if (adj[i].size() == 1){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}