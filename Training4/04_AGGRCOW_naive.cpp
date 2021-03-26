#include <bits/stdc++.h>

using namespace std;

long long n_cases, N, C;

long long count_C(long long radius, vector<long long > p){
    long long last = -radius - 1;
    long long res=0;
    for (const long long &value: p){
        if (value - last >= radius){
            res++;
            last = value;
        }
    }
    
    return res;
}


int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n_cases;
    for (int i=1; i<=n_cases; i++){
        cin >> N >> C;

        vector<long long> positions((long long)N);
        long long max_position = 0;
        for (int i =0; i<N; i++){
            long long temp;
            cin >> temp;
            max_position = max(max_position, temp);
            positions[i] = temp;
        }

        sort(positions.begin(), positions.end());
        for (long long i = max_position; i >= 0; i--){
            if (count_C(i, positions) >= C){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}