#include <bits/stdc++.h>

using namespace std;
long long n;
const int MAX = (int)1e5 + 1;
long long V[MAX];
int q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<long long> A;
    long long min_value = INT_MAX;
    long long max_value = -1e15;
    long long value;
    for (long long i = 1; i<= n; i++) {
        cin >> value;
        A.push_back(value);
        min_value = min(min_value, value);
        max_value = max(max_value, value);
    }
    cin >> q;
    sort(A.begin(), A.end());
    for (int i = 1; i <= q; i++)
    {
        long long value;
        cin >> value;
        if (value < min_value)
        {
            cout << 0 << endl;
        }
        else if (value >= max_value){
            cout << n << endl;
        }
        else
        {
            cout <<  1 + (lower_bound(A.begin(), A.end(), value) - A.begin()) << endl;
        }
    }

    return 0;
}