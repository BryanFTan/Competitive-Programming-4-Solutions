/*
- given sequence denotes the sequence of trains that arrive at B
- each train can leave immediately or "park" at the station
- the station acts as a stack for trains that do not leave immediately
- iterate through 1 .. N, and the given sequence. If match, train leaves immediately, else train gets pushed to the station (stack)
*/
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

    int N;
    while(true) {
        cin >> N;
        if (N == 0) break;
        int i = 1;
        vector<int> arr;
        while(i != 0) {
            cin >> i;
            arr.push_back(i);
            if (arr.size() == N) {
                stack<int> s;
                int pointer = 0;
                for (int j = 1; j <= N; j++) {
                    if (!s.empty() && s.top() == arr[pointer]) {
                        j--;
                        s.pop();
                        pointer++;
                        continue;
                    }
                    if (j != arr[pointer]) {
                        s.push(j);
                    } else {
                        pointer++;
                    }
                }
                while(pointer != N) {
                    if (s.top() != arr[pointer++]) {
                        break;
                    } else {
                        s.pop();
                    }
                }
                if (s.size() > 0) {
                    cout << "No" << "\n";
                } else {
                    cout << "Yes" << "\n";
                }
                arr.clear();
            }
        }
        cout << "\n";
    }

    return 0;
}