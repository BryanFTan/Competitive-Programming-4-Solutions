/*
- all 8, 5-month periods are in deficit (according to question)
- generate all possible order for first 5 months
- then do a complete search for remaining months to find surplus
*/
#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

void search(string builder, int val, int five_month_val, int& max_surplus, int month, int s, int d) {
    if (five_month_val > 0)
        return;
    if (month == 13) {
        max_surplus = max(max_surplus, val);
        return;
    }

    builder[0] == 's' ? five_month_val -= s : five_month_val += d;
    builder.erase(builder.begin());

    search(builder + 's', val + s, five_month_val + s, max_surplus, month + 1, s, d);
    search(builder + 'd', val - d, five_month_val - d, max_surplus, month + 1, s, d);
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, d;
    while(cin >> s >> d) {
        int max_surplus = -1;
        for (int b = 0; b < (1 << 5); b++) {
            int val = 0;
            string builder = "";
            for (int i = 0; i < 5; i++) {
                if (b & (1 << i)) {
                    val += s;
                    builder += 's';
                } else {
                    val -= d;
                    builder += 'd';
                }
            }
            search(builder, val, val, max_surplus, 6, s, d);
        }
        max_surplus > 0 ? 
            cout << max_surplus << "\n" 
            : cout << "Deficit" "\n";
    }

    return 0;
}