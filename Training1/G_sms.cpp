#include <bits/stdc++.h>

using namespace std;

int count(string line, unordered_map<char,int> umap){
    int count = 0;
    for (int i=0; i<line.length(); i++){
        char temp = line[i];
        count += umap[temp];
    }

    return count;
}

int main(){
    unordered_map<char, int> umap;
    umap['a'] = 1; umap['b']=2; umap['c']=3;
    umap['d'] = 1; umap['e']=2; umap['f']=3;

    umap['g'] = 1; umap['h']=2; umap['i']=3;
    umap['j'] = 1; umap['k']=2; umap['l']=3;

    umap['m'] = 1; umap['n']=2; umap['o']=3;
    umap['p'] = 1; umap['q']=2; umap['r']=3; umap['s']=4;

    umap['t'] = 1; umap['u']=2; umap['v']=3;
    umap['w'] = 1; umap['x']=2; umap['y']=3; umap['z']=4;
    umap[' ']=1;

    int t;
    vector<string> lines;
    string line;
    cin >> t;
    for (int i=0; i<t; i++){
        getline(cin, line);
        cin.ignore(2,'\n');
        lines.push_back(line);
    }
    for (int i=0; i<t; i++){
        cout << "--" << endl;
        cout << lines[i];
    }

    return 0;
}