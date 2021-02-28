/*
- Use DFS to jump to reachable squares
- for each reachable square, count the number of squares reachable from it
- maintain an even and odd counter.
*/
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

void dfs(vector<vector<int>> &grid, vector<pair<int, int>> &moves, int &even, int &odd, int x, int y, set<pair<int, int>> &visited) {
    visited.insert({x, y});
    int count = 0;
    set<pair<int, int>> seen;
    int row = x;
    int col = y;
    for (auto m : moves) {
        x = m.first + row;
        y = m.second + col;
        //if out of bounds or water or seen already
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1 || seen.count({x, y})) continue;

        count++;
        seen.insert({x, y});
        if (!visited.count({x, y})) dfs(grid, moves, even, odd, x, y, visited);
    }
    if (count > 0) {
        if (count % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    int idx = 0;
    while(T--) {
        idx++;
        int R, C, M, N;
        cin >> R >> C >> M >> N;
        vector<vector<int>> grid(R, vector<int>(C));
        int W;
        cin >> W;
        while(W--) {
            int x_w, y_w;
            cin >> x_w >> y_w;
            grid[x_w][y_w] = -1;
        }

        int even = 0;
        int odd = 0;
        set<pair<int, int>> visited;
        //8 ways a knight can move
        vector<pair<int, int>> moves = {{M, N}, {N, M}, {-N, M}, {-M, N}, {N, -M}, {M, -N}, {-N, -M}, {-M, -N}};

        dfs(grid, moves, even, odd, 0, 0, visited);

        if (odd == 0 && even == 0) {
            printf("Case %d: %d %d\n", idx, 1, 0);
        } else {
            printf("Case %d: %d %d\n", idx, even, odd);
        }
    }

    return 0;
}