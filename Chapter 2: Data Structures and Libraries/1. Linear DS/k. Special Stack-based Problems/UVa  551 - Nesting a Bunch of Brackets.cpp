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

    string s;
    while (getline(cin, s)) {
        stack<char> stack;
        bool valid = true;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count++;
            switch (s[i]) {
            case '(':
                if (i < s.size() - 1 && s[i + 1] == '*') {
                    stack.push('*');
                    i++;
                } else {
                    stack.push('(');
                }
                break;
            case '[':
                stack.push('[');
                break;
            case '{':
                stack.push('{');
                break;
            case '<':
                stack.push('<');
                break;
            case ']':
                if (stack.top() != '[') {
                    valid = false;
                } else {
                    stack.pop();
                }
                break;
            case '}':
                if (stack.top() != '{') {
                    valid = false;
                } else {
                    stack.pop();
                }
                break;
            case '>':
                if (stack.top() != '<') {
                    valid = false;
                } else {
                    stack.pop();
                }
                break;
            case ')':
                if (stack.top() != '(') {
                    valid = false;
                } else {
                    stack.pop();
                }
                break;
            case '*':
                if (i < s.size() - 1 && s[i + 1] == ')' && stack.top() == '*') {
                    stack.pop();
                    i++;
                } else if (i < s.size() - 1 && s[i + 1] == ')' && stack.top() != '*') {
                    valid = false;
                }
                break;
            default:
                break;
            }
            if (!valid) break;
        }
        if (stack.size() > 0 && valid) {
            valid = false;
            count++;
        } 
        if (!valid) {
            cout << "NO " << count << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }

    return 0;
}