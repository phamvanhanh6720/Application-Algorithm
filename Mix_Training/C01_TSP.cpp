#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 20;
int A[N][N];

int cmin = INT16_MAX;
int best;
int curr_cost;
int used[N];
int location[N];

void TRY(int k){


    for (int i = 1; i<= n; i++){
        if (!used[i] && A[location[k-1]][i]){
            location[k] = i;
            used[i] = 1;

            curr_cost += A[location[k-1]][location[k]];

            if (k==n){
                best = min(best, curr_cost + A[i][0]);
            }

            if (curr_cost + (n-k) *cmin < best){
                TRY(k+1);
            }
            used[i] = 0;
            curr_cost -= A[location[k-1]][location[k]];
        }
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> A[i][j];
            if (A[i][j] != 0){
                cmin = min(cmin, A[i][j]);
            }
        }
    }
    best = INT16_MAX;
    curr_cost = 0;
    used[0] = 1;
    location[0] = 0;
    TRY(1);
    cout << best << endl;


    return 0;
}