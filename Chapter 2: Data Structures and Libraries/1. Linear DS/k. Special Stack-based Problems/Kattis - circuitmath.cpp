/*
- tedious postfix calculator with chars
*/

#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

stack<char> s;
char processing(char opt, char i, char j) {
    switch(opt) {
        case '+': {
            return (i == 'T' || j == 'T') ? 'T' : 'F';
        }
        case '*': { 
            return (i == 'F' || j == 'F') ? 'F' : 'T';
        }   
        case '-': {
            return (i == 'T') ? 'F' : 'T';
        }
            
    }
    return '0';
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    unordered_map<char, char> map;
    for (int i = 0; i < n; i++) {
        char c = (char)('A' + i);
        char b;
        cin >> b;
        map[c] = b;
    }
    char seq;
    while(cin >> seq) {
        char a, b;
        switch(seq) {
            case '+':
            case '*':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(processing(seq, a, b));
                break;
            case '-':
                a = s.top();
                s.pop();
                s.push(processing(seq, a, '0'));
                break;
            default:
                s.push(map[seq]);
                break;
        }
    }
    cout << s.top() << "\n";

    return 0;
}