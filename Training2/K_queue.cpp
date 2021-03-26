#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    vector<long long > A;
    long long temp;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> temp;
        A.push_back(temp);
    }
    int start;
    int end;
    for (int i=0; i< n; i++){
        start = i;
        end = i;
        for (int j=i; j< n; j++){
            if (A[j] == A[i]){
                start = j;
                continue;
            }
            if (A[j]<A[i]){
                end = j;
            }
        }
        cout << end - start - 1 << " ";

    }

    return 0;
}