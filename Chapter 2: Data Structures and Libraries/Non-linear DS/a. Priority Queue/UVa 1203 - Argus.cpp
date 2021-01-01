/*
- use a custom comparator for the max heap, to arrange time as well as qid in ascending order
*/
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

struct comp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        } else {
            return p1.second < p2.second;
        }
    }
};

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "";
    int qid, p;
    vector<pair<int, int>> instr;
    while(true) {
        cin >> s;
        if (s == "#") break;
        cin >> qid >> p;
        instr.push_back(make_pair(p, qid));
    }
    int K;
    cin >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> maxHeap;

    for (int i = 0; i < instr.size(); i++) {
        int time = instr[i].first;
        while(true) {
            if (maxHeap.size() < K) {
                maxHeap.push(make_pair(time, instr[i].second));
            } else {
                if (time > maxHeap.top().first) break;
                maxHeap.push(make_pair(time, instr[i].second));
                if (maxHeap.size() > K) maxHeap.pop();
            }
            time += instr[i].first;
        }
    }

    stack<int> stack;
    while(!maxHeap.empty()) {
        stack.push(maxHeap.top().second);
        maxHeap.pop();
    }
    while(!stack.empty()) {
        cout << stack.top() << "\n";
        stack.pop();
    }

    return 0;
}