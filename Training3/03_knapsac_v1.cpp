#include <bits/stdc++.h>

using namespace std;

long long A[40];
long long C[40];
int mark[40];

int n;
long long b;
long long best_value = 0;
long long weight;
long long value;

void input()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i] >> C[i];
    }
}

void TRY(int k)
{
    if (k > n)
    {
        best_value = weight <= b ? max(best_value, value) : 0;
        return;
    }
    for (int i = 0; i <= 1; i++)
    {

        weight += (i * A[k]);
        value += (i * C[k]);
        if (weight < b)
        {
            TRY(k + 1);
        }
        weight -= (i * A[k]);
        value -= (i * C[k]);
    }
}

int main()
{
    value = 0;
    weight = 0;
    input();
    TRY(1);
    cout << best_value;

    return 0;
}