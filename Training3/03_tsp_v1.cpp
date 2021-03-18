#include <bits/stdc++.h>
#define MAX 21

using namespace std;

int n, m;
long long A[MAX][MAX] ;
int mark[MAX] = {0}; // danh dau cac thanh pho da duyet
int x[MAX];          // luu cac thanh pho da di

long long best = INT_MAX;
long long cmin = INT_MAX;
long long temp_cost=0;

void input()
{
    long long i, j, c;
    for (int z = 0; z < m; z++)
    {
        cin >> i >> j >> c;
        A[i][j] = c;
        cmin = min(cmin, c);
    }
}

void init(){
    for (int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            A[i][j] = 1e6;
        }
    }
}


void try_f(int k)
{
    for (int i = 2; i <= n; i++)
    {
        if (!mark[i])
        {
            x[k] = i;
            if (A[x[k - 1]][x[k]] ==0){
                continue;
            }
            mark[i] = 1;
        
            temp_cost = temp_cost + A[x[k - 1]][x[k]];

            if (k == n)
            {
                best = min(best, temp_cost + A[x[n]][1]);
            }
            if (temp_cost + (n-k+1)* cmin < best) try_f(k+1);
            
            mark[i] = 0;
            temp_cost = temp_cost - A[x[k - 1]][x[k]];
        }
    }
}

int main()
{   cin >> n >> m;
    init();
    input();
    x[1] = 1;
    mark[1] = 1;
    try_f(2);
    cout << best;

    return 0;
}