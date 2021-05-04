/*
- build a map of possible next keys
- do a complete search from the number itself upwards and downwards
- check each digit against the map for validity
*/
#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

unordered_map<int, unordered_set<int>> mapping = {
    {1, {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}},
    {2, {2, 3, 5, 6, 8, 9, 0}},
    {3, {3, 6, 9}},
    {4, {4, 5, 6, 7, 8, 9, 0}},
    {5, {5, 6, 8, 9, 0}},
    {6, {6, 9}},
    {7, {7, 8, 9, 0}},
    {8, {8, 9, 0}},
    {9, {9}},
    {0, {0}}
};

bool possible(int i) {
    int prev = -1;
    while(i) {
        int digit = i % 10;
        i /= 10;
        if (prev != -1 && !mapping[digit].count(prev)) {
            return false;
        }
        prev = digit;
    }
    return true;
}

void search(int i, int original, int& result, unordered_set<int>& seen) {
    if (i == 0 || i > 200)
        return;
    if (seen.count(i))
        return;

    seen.insert(i);
    if (possible(i))  {
        if (abs(original - i) < abs(original - result)) {
            result = i;
        }
        return;
    }

    search(i - 1, original, result, seen);
    search(i + 1, original, result, seen);
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int i;
        cin >> i;
        int result = 0;
        unordered_set<int> seen;
        search(i, i, result, seen);
        cout << result << endl;
    }

    return 0;
}