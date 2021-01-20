//backtracking to check all combinations of rooks
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int max_num = 0;

bool can_place(int col, int row, vector<vector<char>> &board) {
    //check up
    int r1 = row;
    while (r1 >= 0) {
        if (board[r1][col] == 'X') break;
        if (board[r1][col] == 'r') return false;
        r1--;
    }

    //check left
    int c1 = col;
    while(c1 >= 0) {
        if (board[row][c1] == 'X') break;
        if (board[row][c1] == 'r') return false;
        c1--;
    }

    return true;
}

void backtrack(int col, int row, vector<vector<char>> &board, int count) {
    if (row == board.size()) {
        row = 0;
        col++;
    }
    if (col == board.size()) {
        max_num = max(max_num, count);
        return;
    }

    for (int r = row; r < board.size(); r++) {
        if (board[r][col] == 'X') continue;
        if (can_place(col, r, board)) {
            board[r][col] = 'r';
            backtrack(col , r + 1, board, count + 1);
            board[r][col] = '.';
        }
    }
    backtrack(col + 1, 0, board, count);
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while(cin >> n) {
        if (n == 0) break;
        vector<vector<char>> board(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                board[i][j] = c;
            }
        }
        backtrack(0, 0, board, 0);
        cout << max_num << "\n";
        max_num = 0;
    }

    return 0;
}