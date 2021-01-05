/*
- use a map as a max pq to track energy and a nested max pq to track gold
- map<energy, priority_queue<gold>>
- use map.lower_bound to get to next biggest element from x (if not will timeout)
- decrement to get biggest element <= x
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
    cin >> N;
    map<int, priority_queue<int>> pq;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int e, g;
            cin >> e >> g;
            pq[e].push(g);
        } else if (cmd == "query") {
            int x;
            cin >> x;
            long long gold = 0;
            while(!pq.empty() && pq.begin()->first <= x && x > 0) {
                map<int, priority_queue<int>>::iterator it;
                it = pq.lower_bound(x);
                if (it == pq.end()) it--;
                while(it != pq.begin() && it->first > x) it--;
                if (it->first > x) break; 
                x -= it->first;
                gold += it->second.top();
                it->second.pop();
                if (it->second.empty()) pq.erase(it->first);
            }
            cout << gold << "\n";
        }
    }

    return 0;
}