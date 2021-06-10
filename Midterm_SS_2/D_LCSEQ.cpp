#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n;
ll A[N];
ll D[N];
ll max_sum = 0;
int idx;
int length;
vector <int> location;

void Trace(int n)
{

    for (int i = 1; i <= n - 2; i++)
    {
        if (D[n] == D[i] + A[n])
        {
            Trace(i);
            length++;
            break;
        }
    }
    location.push_back(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        D[i] = A[i];
    }

    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i - 2; j++)
        {
            D[i] = max(D[i], D[j] + A[i]);
        }
    }
    idx = N;
    for (int i = n; i >= 1; i--)
    {
        if (max_sum <= D[i])
        {
            max_sum = D[i];
            idx = min(idx, i);
        }
    }
    length = 0;
    Trace(idx);
    cout << max_sum << endl;
    cout << length + 1 << endl;
    for (int v: location){
        cout << v << ' ';
    }
    cout << endl;
}