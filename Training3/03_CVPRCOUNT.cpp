#include <bits/stdc++.h>

using namespace std;
const int N = 20;

int n, K, Q;
long long R;
int d[N];

long long factorial[N];
int n_clients[N];
int sum[N] = {0};
const long long MOD = 1e9 + 7;

void input()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
}

void TRY(int u)
{
    if (u > n)
    {
        long long n_solution = 1;
        for (int i = 1; i <= K; i++)
        {
            n_solution = (n_solution * factorial[n_clients[i]]) % MOD;
            if (n_clients[i] == 0)
            {
                n_solution = 0;
            }
        }

        R = (R + n_solution) % MOD;
        return;
    }

    for (int i=1; i <= K; i++){
        sum[i] += d[u];
        n_clients[i] += 1;
        if (sum[i] <= Q){
            TRY(u+1);
        }
        sum[i] -= d[u];
        n_clients[i] -= 1;
    }


}


int main()
{
    R = 0;
    factorial[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        factorial[i] = factorial[i - 1] * i;
    }
    input();
    TRY(1);
    cout << R / (factorial[K]);

    return 0;
}