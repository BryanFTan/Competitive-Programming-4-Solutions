#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

vector<int> vars(26, 0);
map<int, string> instructions;

vector<string> split_whitespace(string s) {
    string tmp;
    char delim = ' ';
    stringstream ss(s);
    vector<string> v;
    while(getline(ss, tmp, delim)) {
        v.push_back(tmp);
    }
    return v;
}

int intepret_variable(string var) {
    if (isalpha(var[0])) {
        return vars[var[0] - 'A'];
    }
    return stoi(var);
}

int intepret_arithmetic(string arithmetic) {
    //split by white space
    vector<string> v = split_whitespace(arithmetic);
    int var1 = intepret_variable(v[0]);
    if (v.size() == 1) return var1;
    int var2 = intepret_variable(v[2]);
    if (v[1] == "+") {
        return var1 + var2;
    } else if (v[1] == "-") {
        return var1 - var2;
    } else if (v[1] == "*") {
        return var1 * var2;
    }
    return var1/var2;
}

bool intepret_conditional(vector<string> &v) {
    int var1 = intepret_variable(v[0]);
    int var2 = intepret_variable(v[2]);
    if (v[1] == "=") {
        return var1 == var2;
    } else if (v[1] == ">") {
        return var1 > var2;
    } else if (v[1] == "<") {
        return var1 < var2;
    } else if (v[1] == "<>") {
        return var1 != var2;
    } else if (v[1] == "<=") {
        return var1 <= var2;
    }
    return var1 >= var2;
}

void intepret_print(string s) {
    if (s[0] == '"') {
        cout << s.substr(1, s.size() - 2);
    } else {
        cout << vars[s[0] - 'A'];
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int label;
    string line;
    while(cin >> label) {
        getline(cin, line);
        instructions[label] = line;
    }

    map<int, string>::iterator it;
    it = instructions.begin();
    while(it != instructions.end()) {
        string s = it->second;
        s.erase(0, 1); //remove whitespace in front
        int i = s.find_first_of(' ');
        string instr = s.substr(0, i);
        string after_instr = s.substr(i + 1, s.size() - i);

        if (instr == "LET") {
            char var = after_instr[0];
            vars[var - 'A'] = intepret_arithmetic(after_instr.substr(4, after_instr.size()));
            //cout << var << " " << vars[var - 'A'] << "\n";
        } else if (instr == "IF") {
            vector<string> v = split_whitespace(after_instr);
            if (intepret_conditional(v)) {
                it = instructions.find(stoi(v[5]));
                continue;
            }
        } else if (instr == "PRINT") {
            intepret_print(after_instr);
        } else if (instr == "PRINTLN") {
            intepret_print(after_instr);
            cout << "\n";
        }

        it++;
    }


    return 0;
}