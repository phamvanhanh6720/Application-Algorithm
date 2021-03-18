#include <bits/stdc++.h>
#define MAX 40

using namespace std;

long long A[MAX][MAX];
int n;
long long best = INT_MAX;
long long curr = 0;
long long cmin = INT_MAX;

int mark[MAX] = {0};
int save[MAX];

void input()
{
    cin >> n;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> A[i][j];
            if (i!=j){
                cmin = min(cmin, A[i][j]);
            }
        }
    }
}

void TRY(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!mark[i])
        {
            mark[i] = 1;
            save[k] = i;

            int pre_location = save[k - 1];
            int curr_location = i;
            int new_location = i + n;
            save[k + 1] = new_location;

            curr += (A[pre_location][curr_location] + A[curr_location][new_location]);

            if (k == (2*n - 1))
            {
                best = min(curr + A[new_location][0], best);
            }
            if (curr < best) TRY(k+2);
            curr -= (A[pre_location][curr_location] + A[curr_location][new_location]);
            mark[i]=0;
        }
    }
}

int main(){
    input();
    TRY(1);
    cout << best;

    return 0;
}