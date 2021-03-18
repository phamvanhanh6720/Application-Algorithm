#include <bits/stdc++.h>

using namespace std;

bool parentheses(string sample){

    stack<char> s;
    for (int i=0; i < sample.size(); i++){
        char temp = sample[i];
        if (temp == '(' || temp=='[' || temp=='{'){
            s.push(temp);
            continue;
        }
        char top = s.top();
        bool condition_1 = (top =='{' && temp =='}');
        bool condition_2 = (top == '[' && temp == ']');
        bool condition_3 = (top == '(' && temp == ')');
        cout << condition_1;
        if (condition_1 || condition_2 || condition_3){
            s.pop();
        }

    }
    if (s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    char temp_1;
    cin >> temp_1;
    string line;
    vector<string> lines;
    for (int i =0; i<n; i++){
        getline(cin, line);
        lines.push_back(line);
    }

    for (int i =0; i< lines.size(); i++){
        //cout << "--" << lines[i] << endl;
        cout << parentheses(lines[i]) << endl;
    }


    return 0;
}