#include <bits/stdc++.h>

using namespace std;
int n;
const int MAX = 11;
int A[MAX] = {0};
int mark[MAX] = {0};

void print_arr(int A[]){
    for (int i = 1; i<= n; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}

void TRY(int k){
    if (k>n){
        print_arr(A);
        return;
    }
    for (int i = 1; i<=n; i++){
        if (!mark[i]){
            A[k] = i;
            mark[i] = 1;
            TRY(k+1);
            mark[i] = 0;
            A[k] = 0;

        }
    }
}

int  main(){
    cin >> n;
    TRY(1);

    return 0;
}