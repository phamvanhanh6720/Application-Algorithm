#include <bits/stdc++.h>

using namespace std;
const int MAX = 600;
int k, m;
int n_tests;

bool accept(int books[], int max_value)
{
    int res = 0;
    int sum = 0;
    for (int i = m; i >= 1; i--)
    {
        if (sum + books[i] <= max_value)
        {
            sum += books[i];
        }
        else
        {
            sum = books[i];
            if (sum > max_value)
                return false;
            res += 1;
        }
    }
    if (res >= k)
        return false;

    return true;
}

void print_res(int books[], int volumn)
{
    int sum = 0;
    for (int i = 1; i < m; i++)
    {
        sum += books[i];
        cout << books[i] << " ";
        if (sum + books[i + 1] > volumn)
        {
            cout << "/ ";
            sum = 0;
        }
    }
    cout << books[m] << " " << endl;
}

int main()
{
    cin >> n_tests;
    while (n_tests--)
    {
        cin >> m >> k;
        int books[MAX];
        int min_value = INT_MAX;
        int max_value = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> books[i];
            min_value = min(books[i], min_value);
            max_value = max(books[i], max_value);
        }

        for (int i = min_value; i <= 1e9; i++)
        {
            if (accept(books, i))
            {
                print_res(books, i);
                break;
            }
        }
    }
    return 0;
}