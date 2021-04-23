#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[] = {5, 4, 6, 3, 123, 12, 5};
    vector<int> b;
    b.assign(a, a+7);
    sort(b.begin(), b.end());
    for (int &value: b){
        cout << value << endl;
    }
    cout << "===" << endl;
    cout << lower_bound(b.begin(), b.end(), 6) - b.begin() << endl;
    return 0;
}