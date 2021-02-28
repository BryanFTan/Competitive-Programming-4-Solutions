#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

char grid[25][25];
int dir[8][2] = {{1,0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

int dfs(int i, int j, int row, int col) {
    grid[i][j] = '0';
    int result = 1;
    for (int d = 0; d < 8; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        //if out of bounds
        if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] != '1') continue;
        result += dfs(x, y, row, col);
    }
    return result;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cases;
    cin >> cases;
    string s;
    getline(cin, s);
    getline(cin, s);
    while(cases--) {
        int row = 0;
        int n;
        while(getline(cin, s) && s != "") {
            n = s.size();
            for (int col = 0; col < s.size(); col++) {
                grid[row][col] = s[col];
            }
            row++;
        }

        int largest = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    largest = max(largest, dfs(i, j, row, n));
                }
            }
        }
        if (cases > 0) {
            cout << largest << "\n\n";
        } else {
            cout << largest << "\n";
        }
    }
   
    return 0;
}