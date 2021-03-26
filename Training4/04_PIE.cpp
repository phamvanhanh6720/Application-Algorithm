#include <bits/stdc++.h>

using namespace std;
const double PI = acos(-1);

int f(double v, const vector<double> &V){
    int res = 0;
    for(const double &value: V){
        res += floor(value/v);
    }

    return res;
}


int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n_test;
    cin >> n_test;
    while (n_test--){
        int N, F;
        cin >> N >> F;
        vector <double> V(N);
        for (double &value: V){
            int radius;
            cin >> radius;
            value = PI * radius * radius;
        }

        double low= 0, high = PI * 1e4 * 1e4;
        while (high - low > 1e-6){
            double mid = (high +  low) /2;
            if (f(mid, V) < (F+1)){
                high = mid;
            }
            else{
                low = mid;
            }
            //cerr << low << "+" << high << endl;
        }
        cout << fixed << setprecision(6) << low << endl;


    }
    return 0;
}