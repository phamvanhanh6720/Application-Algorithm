#include <bits/stdc++.h>

using namespace std;

const int N = 600;

int n_test;
long long books[N];
long long low, high;
int m, k;

int cal_num_person(int m, long long min_pages){
    int res = 0;
    int temp = min_pages;

    while (m){
        if (books[m] >= temp){
            res += 1;
            temp = min_pages;
        }
        else{
            temp = temp - books[m];
        }
        m--;
        
    }
    return res;
}

int main(){
    int n_slash;
    cin >> n_test;

    while(n_test--){
        low = 0;
        high = 1e7;
        cin >> m >> k;
        n_slash = k - 1;
        for (int i = 1; i <= m; i++){
            cin >> books[i];
        }
        while (high - low > 1){
            long long mid = (high + low) / 2;
            if (cal_num_person(m, mid) >= k){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        int sum = 0;
        for (int i = 1; i <= m; i++){
            cout << books[i] << " ";
            
            sum += books[i];
            if (sum >= low && n_slash){
                cout << " / ";
                sum = 0;
                n_slash--;
            }

        }
        cout << endl;

    }

    return 0;
}