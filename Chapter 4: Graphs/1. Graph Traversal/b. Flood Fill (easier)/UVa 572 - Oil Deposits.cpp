//simple flood fill to get oil pockets
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int dir[8][2] = {{1,0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

void dfs(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = '*';
    for (int d = 0; d < 8; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '@') continue;
        dfs(grid, x, y);
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    while(cin >> m >> n && m) {
        vector<vector<char>> grid(m, vector<char>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                grid[i][j] = c;
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}