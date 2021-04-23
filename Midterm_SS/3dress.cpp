#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 110;
int A[N][N] = {0};
int costs[N] = {0};
int best = INT_MAX;
int curr = 0;
int mark[N] = {0};

vector<int> choose_dress;

bool accept_dress(vector<int> choose_dress, int dress){
    if (choose_dress.empty()) return true;
    for (int i = 0; i< choose_dress.size(); i++){
        if (!A[choose_dress[i]][dress]){
            return false;
        }
    }
    return true;
}

void TRY(int k)
{
    if (k > 3)
    {
        best = min(curr, best);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        
        if (accept_dress(choose_dress, i) && !mark[i]){
            mark[i] = 1;
            curr += costs[i];
            choose_dress.push_back(i);
            TRY(k+1);
            choose_dress.pop_back();
            curr -= costs[i];
            mark[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> costs[i];
    }
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        A[u][v] = 1;
        A[v][u] = 1;
    }
    curr = 0;
    TRY(1);
    if (best >= INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << best << endl;
    }


    return 0;
}