#include <bits/stdc++.h>

using namespace std;
int n;
const int MAX = 1e6 + 1;
int A[MAX];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    long long best = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = A[i];
        for (int j = i + 1; j <= n; j++)
        {
            sum += A[j];
            if (sum % 2 == 0)
            {
                best = max(sum, best);
            }
        }
    }
    if (!best)
    {
        cout << "NOT_FOUND" << endl;
    }
    else
    {
        cout << best << endl;
    }
}