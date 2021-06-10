#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int n, m;
int A[N][N];
vector<int> vertices;
int curr_nodes;
int min_nodes = INT16_MAX;
int used[N];

bool is_accept()
{
    if (curr_nodes <= 1)
    {
        return false;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (used[i] && used[j] && A[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void TRY(int u)
{
    if (u > n)
    {
        if (is_accept())
        {
            min_nodes = min(min_nodes, curr_nodes);
        }

        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        used[u] = i;
        curr_nodes += i;
        TRY(u + 1);
        curr_nodes -= i;
        if (i == 1)
        {
            used[u] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        A[u][v] = 1;
        A[v][u] = 1;
    }
    curr_nodes = 0;
    TRY(1);

    cout << min_nodes << endl;

    return 0;
}