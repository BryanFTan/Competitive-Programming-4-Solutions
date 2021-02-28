#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int dir[8][2] = {{1,0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

void dfs(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = '0';
    for (int d = 0; d < 8; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        //out of bounds or 0
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0') continue;
        dfs(grid, x, y);
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int idx = 0;
    while(cin >> n) {
        idx++;
        vector<vector<char>> grid(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                grid[i][j] = c;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", idx, count);
    }

    return 0;
}