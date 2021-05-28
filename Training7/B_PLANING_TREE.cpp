#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    vector<ll> times;
    cin >> n;

    for (int i = 1; i<= n; i++){
        ll temp;
        cin >> temp;
        times.push_back(temp);
    }
    sort(times.begin(), times.end(), [](ll i, ll j){return i > j;});

    ll curr_day, res;
    curr_day = 1;
    res = 0;
    for (int i = 0; i< n; i++){
        res = max(res, curr_day + 1 + times[i]);
        curr_day += 1;
    }    

    cout << res << endl;

    return 0;
}