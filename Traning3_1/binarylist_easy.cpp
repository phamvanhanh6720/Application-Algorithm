#include <bits/stdc++.h>

using namespace std;
int n;
const int MAX = 21;
int A[MAX];

void print_arr(int A[]){
    for (int i = 1; i<= n ;i++){
        cout << A[i];
    }
    cout << endl;
}

void TRY(int k){
    if (k > n){
        print_arr(A);
        return;
    }
    for (int i=0; i<=1; i++){
        A[k] = i;
        TRY(k+1);
    }
}

int main(){
    cin >> n;
    TRY(1);

    return 0;
}