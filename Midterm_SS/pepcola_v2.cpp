#include <bits/stdc++.h>

using namespace std;
int n;
const int MAX = (int)1e5 + 1;
vector<int> A(MAX);
long long V[MAX];
int q;

int count(const vector<int> &A, int value){
    int low = 0;
    int high = A.size();
    while(high > low){
        if (A[low] < value && value < A[high]){
            high = (int)(high + low) / 2;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> A(n);
    for (int &value : A)
    {
        cin >> value;
    )
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> V[i];
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < A.size(); i++)
    {
        A[i] = A[i - 1] + A[i];
    }

    return 0;
    }