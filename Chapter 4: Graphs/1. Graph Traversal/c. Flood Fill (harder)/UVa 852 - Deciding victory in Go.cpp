//dfs for spaces then for stones
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int dir[4][2] = {{0,1}, {1,0}, {-1, 0}, {0, -1}};
char grid[9][9];
int black, white;
bool seen_black, seen_white;

int dfs_space(int i, int j) {
    grid[i][j] = '-';
    int result = 1;
    for (int d = 0; d < 4; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        if (x < 0 || y < 0 || x >= 9 || y >= 9) continue;
        if (grid[x][y] == 'O') seen_white = true;
        if (grid[x][y] == 'X') seen_black = true;
        if (grid[x][y] == '.') {
            result += dfs_space(x, y);
        }
    }
    return result;
}

int dfs(int i, int j, char color) {
    grid[i][j] = '-';
    int result = 1;
    for (int d = 0; d < 4; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        if (x < 0 || y < 0 || x >= 9 || y >= 9 || grid[x][y] != color) continue;
        result += dfs(x, y, color);
    }
    return result;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c;
                cin >> c;
                grid[i][j] = c;
            }
        }
        black = 0;
        white = 0;
        //count spaces first
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == '.') {
                    //check what stones it can reach
                    seen_black = false;
                    seen_white = false;
                    int count = dfs_space(i, j);
                    if (seen_black && !seen_white) black += count;
                    if (!seen_black && seen_white) white += count;
                }
            }
        }
        //count stones
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == 'O') {
                    white += dfs(i, j, 'O');
                } else if (grid[i][j] == 'X') {
                    black += dfs(i, j, 'X');
                }
            }
        }
        printf("Black %d White %d\n", black, white);
    }

    return 0;
}