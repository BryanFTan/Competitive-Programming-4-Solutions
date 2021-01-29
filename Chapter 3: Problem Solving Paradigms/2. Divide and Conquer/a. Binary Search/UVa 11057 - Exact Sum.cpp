//sort and binary search for the remainder, find the pair with the smallest difference
//2 sum problem
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    while(cin >> N) {
        vector<int> books;
        int difference = 1000001;
        while(N--) {
            int i;
            cin >> i;
            books.push_back(i);
        }
        sort(books.begin(), books.end());
        cin >> M;
        vector<int>::iterator it;
        int a, b;
        for (it = books.begin(); it != books.end() - 1; it++) {
            int target = M - books[it - books.begin()];
            auto it2 = lower_bound(it + 1, books.end(), target);
            if (it2 == books.end() || books[it2 - books.begin()] != target) continue; //not found
            int diff = books[it2 - books.begin()] - books[it - books.begin()];
            if (diff < difference) {
                difference = diff;
                a = books[it - books.begin()];
                b = books[it2 - books.begin()];
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }

    return 0;
}