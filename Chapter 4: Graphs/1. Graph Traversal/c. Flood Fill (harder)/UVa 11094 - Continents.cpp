//flood fill with horizontal overflow
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(vector<vector<char>> &grid, int i, int j, char land) {
    grid[i][j] = '.';
    int result = 1;
    for (int d = 0; d < 4; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        if (y == -1) y = grid[0].size() - 1;
        if (y == grid[0].size()) y = 0;
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != land) continue;
        result += dfs(grid, x, y, land);
    }
    return result;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    while(cin >> M >> N) {
        vector<vector<char>> grid(M, vector<char>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                grid[i][j] = c;
            }
        }
        int X, Y;
        cin >> X >> Y;
        char land = grid[X][Y];
        //remove the land he is currently on
        dfs(grid, X, Y, land);
        
        int largest = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == land) {
                    largest = max(largest, dfs(grid, i, j, land));
                }
            }
        }
        cout << largest << "\n";
    }

    return 0;
}