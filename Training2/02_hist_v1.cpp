#include <bits/stdc++.h>

using namespace std;


unsigned long long find_max_s(unsigned long long n){
    unsigned long long temp;
    vector <unsigned long long> A;
    for (unsigned long long i=0; i!=n; i++){
        cin >> temp;
        A.push_back(temp);
    }
    cin >> temp;
    unsigned long long maxS=0;
    for (unsigned long long start=0; start<n; start++){
        unsigned long long min_height = 0;
        for (unsigned long long end=start; end<n; end++){
            min_height = *min_element(A.begin()+start, A.begin() + end);
            unsigned long long S = min_height * (end-start+1);
            maxS = maxS > S ? maxS : S;
        }
    }
    // cout << maxS;
    return maxS;
}

int main(){
    unsigned long long n;
    vector<unsigned long long> res;
    while (true){
        cin >> n;
        if (n==0){
            break;
        }
        res.push_back(find_max_s(n));
        
    }
    // cout << 5;

    for (unsigned long long i; i!= res.size(); i++){
        cout << res[i] << endl;
    }

    return 0;
}