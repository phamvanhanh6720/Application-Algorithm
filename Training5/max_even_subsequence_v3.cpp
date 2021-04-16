#include <bits/stdc++.h>

using namespace std;

int n;
const int MAX = 1e6 + 1;
long long A[MAX];

long long MaxSumOdd(int i);
long long MaxSumEven(int i);

long long MaxSumOdd(int i)
{
    if (i == 1)
    {
        if (A[i] % 2 != 0)
        {
            return A[i];
        }
        else
        {
            return -(1e15);
        }
    }
    if (A[i] % 2 == 0)
    {
        long long res = MaxSumOdd(i - 1) + A[i];
        return res;
    }
    else
    {
        long long res = max(A[i], MaxSumEven(i - 1) + A[i]);
        return res;
    }
}

long long MaxSumEven(int i)
{
    if (i == 1)
    {
        if (A[i] % 2 == 0)
        {
            return A[i];
        }
        else
        {
            return -(1e15);
        }
    }
    if (A[i] % 2 == 0)
    {
        long long res = max(A[i], MaxSumEven(i - 1) + A[i]);
        return res;
    }
    else
    {
        long long res = MaxSumOdd(i - 1) + A[i];
        return res;
    }
}

int main()
{   

    cin >> n;   
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    long long res = MaxSumEven(n);
    cout << res << endl;

    return 0;
}