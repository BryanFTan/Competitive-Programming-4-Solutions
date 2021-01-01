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

    int v, t;
    while(scanf("%d %d", &v, &t) != EOF) {
        cout << v * t * 2 << "\n";
    }
    return 0;
}
