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

    string cmd;
    unordered_map<string, int> name_to_val;
    unordered_map<int, string> val_to_name;
    while(cin >> cmd) {
        if (cmd == "def") {
            string name;
            int val;
            cin >> name >> val;
            int prev_val;
            if (name_to_val.count(name)) {
                prev_val = name_to_val[name];
                val_to_name.erase(prev_val);
            }
            name_to_val[name] = val;
            val_to_name[val] = name;
        } else if (cmd == "calc") {
            int sum = 0;
            int opt = 1;
            string input;
            string output = "";
            bool not_found = false;
            cin >> input;
            while(input != "=") {
                output += input + " ";
                if (input == "+") {
                    opt = 1;
                } else if (input == "-") {
                    opt = -1;
                } else {
                    if (!name_to_val.count(input)) not_found = true;
                    sum += opt * name_to_val[input];
                }
                cin >> input;
            }
            output += "= ";
            if (val_to_name.count(sum) && !not_found) {
                cout << output << val_to_name[sum] << "\n";
            } else {
                cout << output << "unknown" << "\n";
            }
        } else {
            name_to_val.clear();
            val_to_name.clear();
        }
    }

    return 0;
}