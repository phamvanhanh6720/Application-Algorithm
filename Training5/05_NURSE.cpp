#include <bits/stdc++.h>

using namespace std;
int n, k1, k2;
long long res;
const long long M = (long long)(1e9+7);

void check(int i){
    if ( (i-2) == n || (i-2) == (n-1)){
        res = (res+1) % M;
        return ;
    }
    if (i-2 > n){
        return;
    }

    for (int j = k1; j<=k2; j++){
        check(i+j+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k1 >> k2;
    res = 0;
    check(1);
    check(2);
    cout << res << endl;
    return 0;
}