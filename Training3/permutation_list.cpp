#include <bits/stdc++.h>

using namespace std;

int A[20];
int mark[20] = {0};
int n;

void print_array(int n){
    for(int i=1; i<=n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void try_f (int k){
    for (int i=1; i<=n; i++){
        if (!mark[i]){
            mark[i] = 1;
            A[k] = i;
            if (k==n){
                print_array(n);
            }
            else{
                try_f(k+1);
            }
            mark[i] = 0;
        }
    }

}

int main(){
    cin >> n;
    try_f(1);

    return 0;
}