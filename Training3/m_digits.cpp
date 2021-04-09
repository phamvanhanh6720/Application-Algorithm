#include <bits/stdc++.h>

using namespace std;

int n;
int mark[10] = {0};
int values[10] = {0};
int res = 0;

bool is_accept(int values[])
{
    int sum_1 = values[1] * 100 + values[2] * 10 + values[3];
    int sum_2 = values[5] * 1000 + values[6] * 100 + values[7] * 10 + values[3];
    int total = sum_1 + sum_2 - (values[4] * 100 + 62);
    // cout << total << endl;
    if (total == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_arr(int values[]){
    for (int i=1; i<=8; i++){
        cout << values[i] << ' ';
    }
    cout << endl;
}

void TRY(int k)
{
    if (k > 7)
    {   // print_arr(values);
        bool temp = is_accept(values);
        if (temp == true)
        {
            res += 1;
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!mark[i])
        {
            values[k] = i;
            mark[i] = 1;
            TRY(k + 1);
            values[k] = 0;
            mark[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    TRY(1);
    cout << res << endl;

    return 0;
}