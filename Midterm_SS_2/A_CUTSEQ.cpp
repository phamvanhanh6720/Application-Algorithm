#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 +10;

int check[N];

typedef long long ll;

ll A[N];
int n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i<= n; i++){
        cin >> A[i];
    }

    memset(check, 0, sizeof(check));
    check[1] = 1;
    for (int i = 2; i<= n; i++){
        if (A[i] >= A[i-1]){
            check[i] = 1;
        }
        else{
            check[i] = 0;
        }
    }
    int res = 0;
    for (int i = 1; i<=n; i++){
        res += (!check[i]);
    }

    cout << res + 1 << endl;


    return 0;
}