//shunting-yard algorithm
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
    string s;
    getline(cin, s);
    getline(cin, s);
    while(n--) {
        string postfix;
        stack<string> stack;
        while(getline(cin, s)) {
            if (s.size() == 0) {
                break;
            }
            if (s == "(") {
                stack.push(s);
            } else if (s == ")") {
                while(stack.top() != "(") {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.pop();
            } else if (s == "*" || s == "/") {
                while(!stack.empty()) {
                    if (stack.top() == "(" || stack.top() == "+" || stack.top() == "-") break;
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(s);
            } else if (s == "+" || s == "-") {
                while(!stack.empty()) {
                    if (stack.top() == "(") break;
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(s);
            } else {
                postfix += s;
            }
        }
        while(!stack.empty()) {
            postfix += stack.top();
            stack.pop();
        }
        cout << postfix << "\n";
        cout << "\n";
    }

    return 0;
}