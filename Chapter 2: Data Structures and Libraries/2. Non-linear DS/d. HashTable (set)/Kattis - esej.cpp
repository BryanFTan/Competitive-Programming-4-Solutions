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

    int A, B;
    cin >> A >> B;
    unordered_set<string> words;
    words.insert("");

    srand(time(NULL));
    for (int i = 0; i < B; i++) {
        string word = "";
        while(words.count(word) && word.size() < 15) {
            //randomly generator chars
            int r = rand() % 26;
            word += 'a' + r;
        }
        cout << word << " ";
        words.insert(word);
        if (words.size() > A && words.size() > B/2 + 1) break;
    }
    cout << "\n";

    return 0;
}