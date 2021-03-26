#include <bits/stdc++.h>

using namespace std;

int count_C(int radius, const vector<int > &p){
    int last = -radius - 1;
    int res=0;
    for (const int &value: p){
        if (value - last >= radius){
            res++;
            last = value;
        }
    }
    
    return res;
}

int main(){
    int n_cases, N, C;
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n_cases;
    while(n_cases--){

        cin >> N >> C;
        vector<int>positions(N);
        for (int &value: positions){
            cin >> value;
        }

        sort(positions.begin(), positions.end());
        int low=0, height = (int)1e9 + 10;
        while (height - low > 1){
            int mid = (height + low ) / 2;
            if (count_C(mid, positions) < C){
                height = mid;
            }
            else{
                low = mid;
            }
        }
        cout << low << endl;
    }
    return 0;
}