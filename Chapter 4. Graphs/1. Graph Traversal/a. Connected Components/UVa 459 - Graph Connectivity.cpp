//find connected components
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

void dfs(int i, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[i] = true;
    for (auto n : adj[i]) {
        if (!visited[n]) {
            dfs(n, adj, visited);
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    while(num--) {
        char c;
        cin >> c;
        int n = c - 'A';

        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1);
        string s;
        getline(cin, s);
        while(getline(cin, s)) {
            if (s.size() == 0) break;
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }
        cout << count << "\n\n";
    }

    return 0;
}