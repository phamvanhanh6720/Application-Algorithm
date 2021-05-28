#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef long long ll;
const int N = 2000;

vector<pair<ll, ll>> right_x;
vector<pair<ll, ll>> left_x;

ll n, k;

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        ll x, k;
        cin >> x >> k;
        if (x > 0)
        {
            right_x.push_back({x, k});
        }
        else
        {
            left_x.push_back({abs(x), k});
        }
    }

    sort(right_x.begin(), right_x.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.first < b.first; });

    sort(left_x.begin(), left_x.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return (a.first) < (b.first); });
    ll res = 0;
    ll nest = 0;
    ll pre_location = 0;

    while (!right_x.empty())
    {
        nest += right_x.back().second;

        if (nest >= k)
        {
            res += ((nest / k) * right_x.back().first) << 1;
            nest %= k;
        }

        if (pre_location)
        {
            res += abs(right_x.back().first - pre_location) * 2;
        }

        if (nest != 0)
        {
            pre_location = right_x.back().first;
        }

        right_x.pop_back();
    }

    if (pre_location && nest)
    {
        res += abs(pre_location) * 2;
    }

    nest = 0;
    pre_location = 0;

    while (!left_x.empty())
    {
        nest += left_x.back().second;

        if (nest >= k)
        {
            res += ((nest / k) * left_x.back().first) << 1;
            nest %= k;
        }

        if (pre_location)
        {
            res += abs(left_x.back().first - pre_location) * 2;
        }
        if (nest != 0)
        {
            pre_location = left_x.back().first;
        }

        left_x.pop_back();
    }

    if (pre_location && nest)
    {
        res += abs(pre_location) * 2;
    }

    cout << res << endl;

    return 0;
}