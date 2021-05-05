#include <bits/stdc++.h>
#include <cmath>

using namespace std;
int n;
typedef long long ll;

double cal_distance(pair<ll, ll> coor_1, pair<ll, ll> coor_2){
    double dis;
    dis = (double)pow(coor_1.first - coor_2.first, 2) +(double)pow(coor_1.second - coor_2.second, 2);
    dis = sqrt(dis);

    return dis;
}

int main(){
    cin >> n;
    vector<pair<ll, ll>> coordinates(n);
    for (int i = 0; i< n; i++){
        long long x, y;
        cin >> x >> y;
        coordinates[i].first = x;
        coordinates[i].second = y;
    }
    pair<int, int> res_idx;
    double min_dis=(ll)1e10;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j< n; j++){
            double dis = cal_distance(coordinates[i], coordinates[j]);
            if (dis <= min_dis){
                res_idx.first = i;
                res_idx.second = j;
                min_dis = dis;
            }
        }
    }
    cout << res_idx.first << " " << res_idx.second << " " << fixed << setprecision(6) << min_dis << endl;

    return 0;
}