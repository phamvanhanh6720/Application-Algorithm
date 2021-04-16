#include <bits/stdc++.h>

using namespace std;
int N, M;
const int MAX = 20;
int C[MAX][MAX];
int mark[MAX] = {0};
int cites[MAX] = {0}; 
int cmin = INT_MAX;

int curr_cost = 0;
int res = 0;

void TRY(int k){
    if (k > N){
        int curr_city = cites[k-1];
        int temp = curr_cost;
        temp += C[curr_city][1];
        if(temp <= M){
            res += 1;
        }
        return;
    }
    for (int i=2; i<=N; i++){
        if (!mark[i]){
            mark[i] = 1;
            cites[k] = i;
            curr_cost += C[cites[k-1]][i];
            if ((curr_cost + (N- k + 1) * cmin) <= M){
                TRY(k+1);
            }
            curr_cost -= C[cites[k-1]][i];
            cites[k] = 0;
            mark[i] = 0;
        }
    }
}

int main(){
    cites[1] = 1;
    mark[1] = 1;
    cin >> N >> M;
    for (int i = 1; i<= N; i++){
        for (int j = 1; j<= N; j++){
            cin >> C[i][j];
            if (i != j){
                cmin = min(C[i][j], cmin);
            }
        }
    }
    TRY(2);
    cout << res<< endl;

    return 0;
}