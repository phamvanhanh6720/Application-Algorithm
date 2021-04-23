#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e6 + 1;
int a[N];
int F[N];

int main(){
    cin >> n;
    for (int i = 1; i<= n; i++){
        cin >> a[i];
    }
    int res = 0;
    F[1] = a[1];
    for (int i = 2; i<= n; i++){
        F[i] = max(F[i-1]+a[i], a[i]);
        res = max(res, F[i]);
    }
    cout << res << endl;
    return 0;
}