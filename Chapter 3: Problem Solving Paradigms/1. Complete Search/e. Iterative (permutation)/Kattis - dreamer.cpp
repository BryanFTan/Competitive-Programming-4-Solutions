//permutate through all dates and count valid dates
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

struct date {
    int day;
    int month;
    int year;
    date(int d, int m, int y) : day(d), month(m), year(y) {}
};

bool leap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

bool is_valid(int day, int month, int year) {
    if (year < 2000 || day > 31 || month > 12 || day < 1 || month < 1) return false;
    vector<int> days = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leap(year)) days[2]++;
    if (day > days[month]) return false;
    return true;
}

void check_min(date &min_day, int day, int month, int year) {
    if (year < min_day.year || (year == min_day.year && month < min_day.month) || (year == min_day.year && month == min_day.month && day < min_day.day)) {
        min_day.day = day;
        min_day.month = month;
        min_day.year = year;
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> permutation;
        int count = 0;
        date min_day(31, 12, 9999);
        for (int i = 0; i < 3; i++) {
            string s;
            cin >> s;
            for (char& c : s) {
                permutation.push_back(c - '0');
            }
        }
        sort(permutation.begin(), permutation.end());
        do {
            int day = permutation[0] * 10 + permutation[1];
            int month = permutation[2] * 10 + permutation[3];
            int year = permutation[4] * 1000 + permutation[5] * 100  + permutation[6] * 10 + permutation[7];
            if (is_valid(day, month, year)) {
                count++;
                check_min(min_day, day, month, year);
            }
        } while (next_permutation(permutation.begin(), permutation.end()));
        if (count == 0) {
            cout << 0 << "\n";
        } else {
            cout << count << " ";
            if (min_day.day < 10) cout << 0;
            cout << min_day.day << " ";
            if (min_day.month < 10) cout << 0;
            cout << min_day.month << " ";
            cout << min_day.year << "\n";
        }
    }

    return 0;
}