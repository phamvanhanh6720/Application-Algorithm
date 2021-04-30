#include<bits/stdc++.h>

using namespace std;
int n,k;
const int N = 5001;
int a[N];

int main(){
    cin >> n >> k;
    for (int i = 1; i<= n; i++){
        cin >> a[i];
    }
    int res = 0;
    for (int x = 1; x <= n; x++){
        for (int y = x+1; y <= n; y++){
            for (int z = y+1; z<= n; z++){
                int sum = 0;
                sum += (a[x] + a[y] + a[z]);
                if (!(x==y || y==z)){
                   if (sum == k){
                       res++;
                   } 
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}