#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6 + 1;
int n;
typedef long long ll;
vector<ll> A;
vector<int> ids;

int L[N];
int R[N];

int main()
{
    cin >> n;
    ll temp;
    memset(L, -1, sizeof(L));
    memset(R, -1, sizeof(R));
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        A.push_back(temp);
        ids.push_back(i);
        L[i] = i - 1;

        R[i] = i + 1;
    }
    sort(ids.begin(), ids.end(), [](int i, int j)
         { return A[i] > A[j]; });

    ll total_cost = 0;

    int index;
    for (int i = 0; i < ids.size(); i++)
    {
        index = ids[i];
        if (index != (n - 1))
            L[R[index]] = L[index];

        if (index != 0)
            R[L[index]] = R[index];

        total_cost += A[index];
        if (L[index] != -1)
        {
            total_cost += A[L[index]];
        }
        if (R[index] != -1)
        {
            total_cost += A[R[index]];
        }
    }
    cout << total_cost << endl;

    return 0;
}