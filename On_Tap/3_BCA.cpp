#include <bits/stdc++.h>

using namespace std;

const int N = 30;
const int M = 15;
int m, n;

int conflict[N][N];
int can_teach[M][N];
int assign[N];

int best_load = INT32_MAX;
int load[M]={0};


bool can_assign(int t, int c){
    for (int i = 1; i <= n; i++){
        if (assign[i] == t && conflict[i][c]){
            return false;
        }
    }
    return true;
}


void TRY(int k)
{
    if (k > n){
        int max_load;
        for (int t = 1; t <= m; t++){
            max_load = max(max_load, load[t]);
        }
        if (max_load)
            best_load = min(best_load, max_load);
        return;
    }

    for (int t = 1; t <= m; t++){
        if (can_teach[t][k] && can_assign(t, k)){
            load[t] += 1;
            assign[k] = t;

            if (load[t] < best_load)
                TRY(k+1);

            load[t] -= 1;
            assign[k] = 0;
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int c;
            cin >> c;
            can_teach[i][c] = 1;
        }
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        conflict[u][v] = conflict[v][u] = 1;
    }
    TRY(1);
    cout << best_load << endl;

    return 0;
}