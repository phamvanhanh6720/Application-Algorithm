#include <bits/stdc++.h>

using namespace std;
int n;
const int MAX = (int) 1e5 + 1;
int A[MAX];
int V[MAX];
int q;

int count(int A[], int value){
    int res = 0;
    for (int i = 1; i<= n; i++){
        if (A[i] <= value){
            res += 1;

        }
    }
    return res;
}

int main(){
    cin >> n;
    for (int i = 1; i<= n; i++){
        cin >> A[i];
    }
    cin >> q;
    for (int i = 1; i<= q; i++){
        cin >> V[i];
    }
    for (int i = 1; i<= q; i++){
        int res = count(A, V[i]);
        cout <<res << endl;
    }

    return 0;
}