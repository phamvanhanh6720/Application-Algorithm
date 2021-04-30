#include <bits/stdc++.h>

using namespace std;
const int MAX = 600;
int k, m;
int n_tests;
int books[MAX];
bool split[MAX];

bool accept(long long max_value, bool show)
{
    int res = 1;
    long long sum = 0;
    if (show)
    {
        memset(split, 0, sizeof(split));
    }
    for (int i = m; i >= 1; i--)
    {   
        if (books[i] > max_value) return false;
        if (sum + books[i] <= max_value)
        {
            sum += books[i];
        }
        else
        {
            sum = books[i];
            res++;
            if (show)
            {
                split[i] = 1;
            }
        }
    }
    if (show)
    {   cout << "res" << res << endl;
        for (int i = 1; i <= m; i++){
            cout << books[i] << " ";
            if (split[i] || res < k){
                cout << "/ ";
                res++;
            }
        }
        cout << endl;
    }
    return res <= k;
}

int main()
{
    cin >> n_tests;
    while (n_tests--)
    {
        cin >> m >> k;

        for (int i = 1; i <= m; i++)
        {
            cin >> books[i];
        }
        long long low = 0, high = 1e10;
        long long mid;
        while (high - low > 1)
        {
            mid = (high + low) / 2;
            if (accept(mid, 0))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        //accept(high, 1);
        cout << high << endl;

    }
    return 0;
}