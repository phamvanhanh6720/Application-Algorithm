#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAX = 20;
int A[MAX] = {0};


void print_arr(int A[]){
    for (int i = 1; i <= m; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}

void TRY(int k){
    if (k > m){
        print_arr(A);
        return;
    }
    for (int i = A[k-1] + 1; i<= (n-m+k); i++){
        A[k] = i;
        TRY(k+1);
        A[k] = 0;
    }
}

int main(){
    cin >> n >> m;
    TRY(1);
    return 0;
}