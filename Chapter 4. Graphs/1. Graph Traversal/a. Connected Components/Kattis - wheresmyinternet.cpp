//simply dfs from vertex 1
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

set<int> has_internet;

void dfs(int i, vector<vector<int>> &adj) {
    has_internet.insert(i);
    for (auto n : adj[i]) {
        if (!has_internet.count(n)) {
            dfs(n, adj);
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    while(M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, adj);

    if (has_internet.size() == N) {
        cout << "Connected" << "\n";
    } else {
        for (int i = 1; i <= N; i++) {
            if (!has_internet.count(i)) {
                cout << i << "\n";
            }
        }
    }

    return 0;
}