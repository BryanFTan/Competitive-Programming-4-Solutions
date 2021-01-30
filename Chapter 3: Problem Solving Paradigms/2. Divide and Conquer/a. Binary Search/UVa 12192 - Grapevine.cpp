//for each row, lower_bound search to find top left corner of square. Since is square can check bottom right corner to find biggest square possible.
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        int arr[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int h;
                cin >> h;
                arr[i][j] = h;
            }
        }

        int Q;
        cin >> Q;
        while(Q--) {
            int L, U;
            cin >> L >> U;
            int length = 0;
            for (int r = 0; r < N; r++) {
                if (r + length >= N) break; //square bigger than remaining
                int pos = lower_bound(arr[r], arr[r] + M, L) - arr[r];
                for (int c = length; c < N; c++) {
                    if (r + c >= N || pos + c >= M || arr[r + c][pos + c] > U) break;
                    length = max(length, c + 1);
                }
            }
            cout << length << "\n";
        }
        cout << "-" << "\n";
    }

    return 0;
}