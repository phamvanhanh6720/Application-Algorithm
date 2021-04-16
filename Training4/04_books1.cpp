#include <bits/stdc++.h>

using namespace std;
const int MAX = 600;
int k, m;
int n_tests;

int count_S(int books[],int volumn){
    int res = 0;
    int sum = 0;
    for (int i = 1; i<=m; i++){
        sum += books[i];
        if (sum > volumn){
            res += 1;
            sum = books[i];
        }
    }

    return res;
}

void print_res(int books[], int volumn){
    int sum = 0;
    for (int i = 1; i<= m; i++){
        sum += books[i];
        cout << books[i] << ' ';
        if (sum > )
    }
}

int main()
{
    cin >> n_tests;
    while (n_tests--)
    {
        cin >> m >> k;
        int books[MAX];
        for (int i = 1; i <= m; i++)
        {
            cin >> books[i];
        }
    }
    return 0;
}