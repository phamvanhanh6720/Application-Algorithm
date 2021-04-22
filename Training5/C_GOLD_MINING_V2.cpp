#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e6 + 1;
int a[N];
int L1, L2;
int F[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L1 >> L2;
    for (int i =1; i<= n; i++){
        cin >> a[i];
    }
    
    for (int i = 1; i<= n; i++){
        F[i] = a[i];
    }
    for (int i = L1+1; i<=n; i++){
        for (int j = i - L2; j<= i - L1; j++){
            if (j <= 0) continue;
            F[i] = max(F[i], F[j] + a[i]);
        }
    }
    int res = 0;
    for (int i = 1; i<=n; i++){
        res = max(res, F[i]);
    }
    cout << res << endl;
    

    return 0;
}