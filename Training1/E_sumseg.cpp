#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned int n;
    long long a;
    const long long m = 1e9 + 7;
    cin >> n;
    long long res = 0;
    for (int i=0; i< n; i++){
        cin >> a;
        res = ((a % m) + res) % m;
    }
    cout << res;
}