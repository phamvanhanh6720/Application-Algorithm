#include <bits/stdc++.h>

using namespace std;

int n;
long long total_cost;
vector<long long> A;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        A.push_back(temp);
    }
    total_cost = 0;
    while (A.size() >= 2)
    {
        int idx_max;
        idx_max = max_element(A.begin(), A.end()) - A.begin();
        if (idx_max == 0)
        {
            total_cost += (A[idx_max] + A[idx_max + 1]);
        }
        else if (idx_max == A.size() - 1)
        {
            total_cost += (A[idx_max] + A[idx_max - 1]);
        }
        else
        {
            total_cost += (A[idx_max] + A[idx_max - 1] + A[idx_max + 1]);
        }
        A.erase(A.begin() + idx_max);
    }
    
    total_cost += A[0];
    cout << total_cost << endl;

    return 0;
}