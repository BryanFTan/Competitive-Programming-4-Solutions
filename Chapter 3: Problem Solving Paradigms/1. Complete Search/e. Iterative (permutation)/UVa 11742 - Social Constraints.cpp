//check each permutation to see if it fits all the constraints
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

struct constraint {
    int a;
    int b;
    int c;
    constraint(int a, int b, int c) : a(a), b(b), c(c) {}
};

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    while(cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<constraint> constraints;
        while(m--) {
            int a, b, c;
            cin >> a >> b >> c;
            constraint con(a, b, c);
            constraints.push_back(con);
        }
        vector<int> permutation;
        int count = 0;
        for (int i = 0; i < n; i++) permutation.push_back(i);
        do {
            //check permutation
            vector<int> position(n);
            for (int i = 0; i < n; i++) {
                position[permutation[i]] = i;
            }
            bool valid = true;
            for (auto &con : constraints) {
                if (con.c < 0) {
                    valid = abs(position[con.a] - position[con.b]) >= abs(con.c) ? true : false;
                } else {
                    valid = abs(position[con.a] - position[con.b]) <= con.c ? true : false;
                }
                if (!valid) break;
            }
            if (valid) count++;
        } while(next_permutation(permutation.begin(), permutation.end()));
        cout << count << "\n";
    }

    return 0;
}