#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int A[100];
    int num_negative=0, num_positive=0, num_zero=0;
    vector<int> set_neg, set_pos, set_zero;
    vector<int> neg, pos, zero;
    for (int i=0; i!= n; i++){
        cin >> A[i];
        if (A[i] > 0){
            num_positive +=1;
            pos.push_back(A[i]);
        }
        else if (A[i] < 0){
            num_negative +=1;
            neg.push_back(A[i]);
        }
        else{
            num_zero += 1;
            set_zero.push_back(A[i]);
        }
    }
    if (num_negative % 2 == 1){
        set_neg.push_back(neg[0]);
        for (int i=1; i<num_negative; i++){
            set_pos.push_back(neg[i]);
        }

        for (int i=0; i<num_positive; i++){
            set_pos.push_back(pos[i]);
        }
    }
    else{
        set_neg.push_back(neg[0]);
        set_zero.push_back(neg[1]);
        for (int i=2; i<num_negative; i++){
            set_pos.push_back(neg[i]);
        }

        for (int i=0; i<num_positive; i++){
            set_pos.push_back(pos[i]);
        }

    }

    cout << set_neg.size() << " ";
    for (int i=0; i< set_neg.size(); i++){
        cout << set_neg[i] << " ";
    }
    cout << endl;

    cout << set_pos.size() << " ";
    for (int i=0; i< set_pos.size(); i++){
        cout << set_pos[i] << " ";
    }
    cout << endl;

    cout << set_zero.size() << " ";
    for (int i=0; i< set_zero.size(); i++){
        cout << set_zero[i] << " ";
    }
    cout << endl;


    return 0;
}