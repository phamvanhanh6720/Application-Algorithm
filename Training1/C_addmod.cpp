#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long a,b;
    cin >> a >> b;

    const unsigned long long c = 1e9 + 7;

    unsigned long long res_1, res_2, res;
    res_1 = a % c;
    res_2 = b % c;
    res = (res_1 +  res_2) % c;
    cout << res;

    return 0;
}