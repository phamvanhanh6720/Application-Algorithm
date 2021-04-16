#include <bits/stdc++.h>

using namespace std;
const long long n = (long long) (1e9 + 7);

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    long long res = 1;
    long long temp;
    cin >> N;
    
    for (int i = 1; i<= N; i++){
        cin >> temp;
        res  = (res * temp) % n;
    } 
    cout << res << endl;
}