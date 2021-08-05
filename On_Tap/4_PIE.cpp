#include <bits/stdc++.h>
#include <cmath>

using namespace std;

const int N = 1e4+1;
const double PI = 3.14159;

double V[N];
int n_test;
int n, f;

double low, high;

double device(double v, int n){
    double res = 0;
    for (int i = 1; i<= n; i++){
        res += floor(V[i] / v);
    }
    
    return res;
}

int main(){
    cin >> n_test;
    memset(V, sizeof(V), 0);
    while (n_test--){
        cin >> n >> f;
        for (int i = 1; i<=n; i++){
            int r;
            cin >> r;
            V[i] = PI * r * r;
        }
    low = 0;
    high = PI * 1e4 * 1e4;
    while(high-low > 1e-6){
        double mid = (high + low) / 2;
        if (device(mid, n) >= (f+1)){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    cout << fixed <<setprecision(6) << low << endl;

    }
    return 0;
}