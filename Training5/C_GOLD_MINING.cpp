#include <bits/stdc++.h>

using namespace std;
int n, L1, L2;
const int MAX = 1e6 + 1;
int A[MAX];

int DP(int i){
    if (i == 1){
        return A[i];
    }
    int res = 0;
    for (int j = i; j >= 1; j--){
        int temp = i - j;
        if (temp >= L1 && temp <= L2){
            res = max(res, DP(j)+ A[j]);
        }
    }
    return res;
}

int main(){
    cin >> n >> L1 >> L2;
    for (int i = 1; i<= n; i++){
        cin >> A[i];
    }
    int best = 0;
    best = DP(n);
    cout << best << endl;

    return 0;
}