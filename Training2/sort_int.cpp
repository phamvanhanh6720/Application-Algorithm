#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp;
    std::vector<int> A;
    for (int i = 0; i != n; i++)
    {   cin >> temp;
        A.push_back(temp);
    }

    std::sort(A.begin(), A.end());

    for (int i=0; i!=n; i++){
        cout << A[i] << " ";
    }

    return 0;
}