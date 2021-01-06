/*
- use a nested map to compare both infection level and order
- map<infection_lvl, map<order, cat name>>
*/

#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

unordered_map<string, int> cat_to_order;
unordered_map<int, string> order_to_cat;
map<int, map<int, string>> val_to_cats;
unordered_map<string, int> cat_to_val;

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int order = 0;
    while(N--) {
        order++;
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            string name;
            int inf;
            cin >> name >> inf;
            cat_to_order[name] = order;
            order_to_cat[order] = name;
            cat_to_val[name] = inf;
            val_to_cats[inf][order] = name;
        } else if (cmd == 1) {
            string name;
            int inf;
            cin >> name >> inf;
            int order = cat_to_order[name];
            int old_inf = cat_to_val[name];
            val_to_cats[old_inf].erase(order);
            if (val_to_cats[old_inf].empty()) val_to_cats.erase(old_inf);
            inf += old_inf;
            val_to_cats[inf][order] = name;
            cat_to_val[name] = inf;
        } else if (cmd == 2) {
            string name;
            cin >> name;
            int order = cat_to_order[name];
            int inf = cat_to_val[name];
            val_to_cats[inf].erase(order);
            if (val_to_cats[inf].empty()) val_to_cats.erase(inf);
            cat_to_val.erase(name);
        } else if (cmd == 3) {
            if (val_to_cats.empty()) {
                cout << "The clinic is empty" << "\n";
            } else {
                cout << val_to_cats.rbegin()->second.begin()->second << "\n";
            }
        }
    }

    return 0;
}