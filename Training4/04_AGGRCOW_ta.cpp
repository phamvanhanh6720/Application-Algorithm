#include <bits/stdc++.h>

using namespace std;

int f(const vector<int> &x, int d) {
    int res = 0;
    int last = -d - 1;
    for (const int &value : x) {
        if (value - last >= d) {
            res++;
            last = value;
        }
    }
    return res;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for (int &value : x) {
        cin >> value;
    }
    sort(x.begin(), x.end());
    int low = 0, high = (int)1e9 + 10;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (f(x, mid) < c) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << low << '\n';
  }
  return 0;
}