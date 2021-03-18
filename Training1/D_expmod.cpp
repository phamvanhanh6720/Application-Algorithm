#include <bits/stdc++.h>

using namespace std;

long long expMod(unsigned long long a, unsigned long long b, unsigned long long m){
    if (b==0){
        return 1;
    }
    long long c = expMod(a, b/2, m);
    if (b%2==0){
        return (c * c) % m;
    }
    else{
        long long a_du = a % m;
        long long cc = (c * c) % m;
        return (a_du * cc) % m;
    }
}

int main(){
    unsigned long long a, b;
    const unsigned long long m = 1e9 + 7;
    cin >> a >> b;
    cout << expMod(a, b, m);

    return 0;
}