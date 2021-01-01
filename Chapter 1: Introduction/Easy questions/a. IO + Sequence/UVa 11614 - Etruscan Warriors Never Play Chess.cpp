#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);

int main()
{
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, root;
    unsigned long long n;
    cin >> i;
    while (i--)
    {
        cin >> n;
        root = (-1 + sqrt(1 + 8*n)) / 2;
        cout << root << "\n";
    }
    return 0;
}