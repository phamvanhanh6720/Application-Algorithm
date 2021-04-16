#include <bits/stdc++.h>

using namespace std;
int n;
const int MAX = 1e6 + 1;
int A[MAX];
long long prefix_sum[MAX] = {0};

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    prefix_sum[1] = A[1];
    for (int i = 2; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    long long max_odd_r = -(1e15);
    long long max_even_r = -(1e15);
    long long min_odd_l = 1e15;
    long long  min_even_l = 1e15;

    for (int i = 1; i <= n; i++)
    {
        long long temp = A[i];
        if (temp % 2 ==0 ){
            max_even_r = max(max_even_r, temp);
            min_even_l = min(min_even_l, temp);
        }
        else{
            max_odd_r = max(max_odd_r , temp);
            min_odd_l = min(min_odd_l, temp);
        }

        
        
    }
    long long res1 = (max_odd_r - min_odd_l);
    long long res2 = (max_even_r - min_even_l);
    cout << max(res1, res2);
}