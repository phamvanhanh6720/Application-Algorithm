#include <bits/stdc++.h>

using namespace std;

long long n,m;
const long long MAX = 1e6+1;
long long heights[MAX] = {0};

long long min_height = INT_MAX;
long long max_height = 0;
void input(){
    cin >> n >> m;
    for (long long i=1; i<=n; i++){
        long long temp;
        cin >> temp;
        heights[i] = temp;
        min_height = min(min_height, heights[i]);
        max_height = max(max_height, temp);
    }
}

long long sum_wood(long long threshold){
    long long res = 0;
    for (long long i = 1; i<=n; i++){
        res += max((long long)0, heights[i] - threshold);
    }

    return res;
}

int main(){
    input();
    for (long long i = max_height; i>=min_height; i--){
        long long threshold = i;
        if (sum_wood(threshold) >= m){
            cout << threshold << endl;
            break;
        }
    }

    return 0;
}