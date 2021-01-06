//sort the courses and cocatenate them together as key for hashmap
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

    int n;
    cin >> n;
    unordered_map<string, int> map;
    int max = 0;
    while (n--) {
        vector<int> courses(5);
        int course;
        for (int i = 0; i < 5; i++) {
            cin >> course;
            courses[i] = course;
        }
        sort(courses.begin(), courses.end());
        string s = "";
        for (int i : courses) {
            s += to_string(i);
        }
        map[s]++;
    }
    int total = 0;
    for (auto it : map) {
        if (it.second > max) {
            max = it.second;
            total = it.second;
        } else if (it.second == max) {
            total += it.second;
        }
    }
    cout << total << "\n";

    return 0;
}

