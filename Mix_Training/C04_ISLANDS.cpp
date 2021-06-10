#include <bits/stdc++.h>

using namespace std;
int n_islands;
int max_s = 0;

int n, m;
const int N = 100;
int A[N][N];
int used[N][N];
int s;

void dfs(int i, int j)
{
    //cout << i << j << endl;
    used[i][j] = 1;
    s++;

    // up
    if (i - 1 >= 1 && A[i - 1][j])
    {
        if (!used[i - 1][j])
            dfs(i - 1, j);
    }

    // down
    if (i + 1 <= n && A[i + 1][j])
    {
        if (!used[i + 1][j])
            dfs(i + 1, j);
    }

    // left
    if (j - 1 >= 1 && A[i][j - 1])
    {
        if (!used[i][j - 1])
            dfs(i, j - 1);
    }

    //right
    if (j + 1 <= m && A[i][j + 1])
    {
        if (!used[i][j + 1])
            dfs(i, j + 1);
    }

    return;
}

int main()
{
    cin >> n >> m;
    //char temp;
    //cin >> temp;
    string line;
    getline(cin, line);

    for (int i = 1; i <= n; i++)
    {
        string line;
        getline(cin, line);
        for (int j = 1; j <= m; j++)
        {
            A[i][j] = line[j - 1] - '0';
            if (A[i][j] == 0)
            {
                used[i][j] = 1;
            }
        }
    }

    n_islands = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!used[i][j])
            {
                n_islands++;
                s = 0;
                dfs(i, j);
                max_s = max(s, max_s);
            }
        }
    }
    cout << n_islands << endl;
    cout << max_s << endl;

    return 1;
}