#include <bits/stdc++.h>

using namespace std;

void print_arr(int bits[], int n){
    for (int i =0 ; i<n; i++){
        cout << bits[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int n;
    const int MAX = 1e4 + 1;
    int bits[MAX] = {};

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> bits[i];
    }
    bool res = next_permutation(bits, bits + n);
    if (!res){
        cout << -1 << endl;
    }
    else{
        print_arr(bits, n);
    }

    return 0;
}