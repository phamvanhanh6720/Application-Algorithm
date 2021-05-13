#include <bits/stdc++.h>

using namespace std;


struct edge{
    int u, v;
    long long weight;
    edge(int u_, int v_, long long w_){
        u = u_;
        v = v_;
        weight = w_;
    }
};

struct UnionFind{
    vector<int> iParent;
    UnionFind(int n){
        iParent = vector<int>(n+1);
        for (int i = 1; i<=n; i++){
            iParent[i] = i;
        }
    }
    int Find(int x){
        if (iParent[x] == x){
            return x;
        }
        else{
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }
    void Union(int x, int y){
        iParent[Find(x)] = Find(y);
    }
};

bool edge_cmp(const edge &a, const edge &b){
    return a.weight < b.weight;
}

vector<edge> MST(int n, vector<edge> edges){
    UnionFind uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    vector <edge> res;

    for (int i = 0; i<edges.size(); i++){
        int u = edges[i].u;
        int v = edges[i].v;
        if (uf.Find(u) != uf.Find(v)){
            uf.Union(u, v);
            res.push_back(edges[i]);
        }
    }

    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    long long min_weight = 0;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
    }
    vector<edge> res = MST(n, edges);

    for (int i = 0; i < res.size(); i++){
        min_weight += (res[i].weight);
    }
    cout << min_weight << endl;

    return 0;
}