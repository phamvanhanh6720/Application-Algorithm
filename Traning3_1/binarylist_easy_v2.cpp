#include <bits/stdc++.h>

using namespace std;
int n;
const int MAX = 21;
int A[MAX] = {0};

void print_arr(int A[]){
    for (int i = 0; i< n; i++){
        cout << A[i];
    }
    cout << endl;
}

void TRY(int k){
    for (int i = 0; i<= 1; i++){
        A[k] = i;
        if (k==n){
            print_arr(A);
            return;
        }
        TRY(k+1);
    }
}


int main(){
    cin >> n;
    TRY(0);

    return 0;
}