#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e4 + 1;
int a[N];
int max_length = 0;

int iMem[10001];

int LIS(int i){
    if (iMem[i] != -1){
        return iMem[i];
    }
    int res = 1;
    for (int j = 1; j < i; j++){
        if (a[j] < a[i]){
            res = max(res, 1 + LIS(j));
        }
    }
    iMem[i] = res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
    }
    memset(iMem, -1, sizeof(iMem));
    iMem[1] = 1;
    LIS(n);
    int pos = 0;
    int ans = 0;
    for (int i = 1; i<=n; i++){
        ans = max(ans, iMem[i]);
        if (ans == iMem[i]) pos = i;
    }
    cout << ans;

    return 0;
}