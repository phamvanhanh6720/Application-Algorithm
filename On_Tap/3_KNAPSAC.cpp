#include <bits/stdc++.h>

using namespace std;
const int N = 40;
int n;
long long b;

long long A[N];
long long C[N];

long long curr_w = 0;
long long curr_c = 0;
long long best_c = 0;

int mark[N];

void TRY(int k)
{
    if (k > n)
    {
        if (curr_w <= b)
        {
            best_c = max(best_c, curr_c);
        }

        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        curr_c += i * C[k];
        curr_w += i * A[k];
        if (curr_w <= b)
            TRY(k + 1);
        curr_c -= i * C[k];
        curr_w -= i * A[k];
    }
}

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        long long a, c;
        cin >> a >> c;
        A[i] = a;
        C[i] = c;
    }
    TRY(1);
    cout << best_c << endl;
    return 0;
}