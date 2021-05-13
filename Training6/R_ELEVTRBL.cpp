#include <bits/stdc++.h>

using namespace std;
int f, s, g, u, d;
int res;
int depth;
const int N = 1e6;
bool is_visited[N];

void dfs(int position)
{
    is_visited[position] = true;

    if (position == g)
    {
        res = min(res, depth);
        return;
    }
    if (position + u <= f && !is_visited[position + u])
    {
        depth++;
        dfs(position + u);
        depth--;
    }
    if (position - d >= 1 && !is_visited[position - d])
    {
        depth++;
        dfs(position - d);
        depth--;
    }

    return;
}

int main()
{

    cin >> f >> s >> g >> u >> d;
    res = INT_MAX;
    depth = 0;
    dfs(s);

    if (!is_visited[g])
    {
        cout << "use the stairs" << endl;
    }
    else
    {
        cout << res << endl;
    }
    return 0;
}