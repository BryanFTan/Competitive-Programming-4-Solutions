#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = '.';
    for (int d = 0; d < 4; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '.') continue;
        dfs(grid, x, y);
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
        int N;
        cin >> N;
        vector<vector<char>> grid(N, vector<char>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                grid[i][j] = c;
            }
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'x') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        printf("Case %d: %d\n", idx, count);
    }

    return 0;
}