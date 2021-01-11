#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

class UnionFind {
private:
    vector<int> parent, size;
    int num_sets;
public:
    UnionFind(int N) {
        parent.assign(N, 0);
        size.assign(N, 0);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        num_sets = N;
    }

    int find_set(int i) {
        if (i == parent[i])
            return i;
        return parent[i] = find_set(parent[i]);
    }

    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    void union_set(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (size[i] < size[j])
                swap(i, j);
            parent[j] = i;
            size[i] += size[j];
        }
        num_sets--;
    }

    int count_sets() {
        return num_sets;
    }
};

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    UnionFind UF(N);

    while(Q--) {
        string opt;
        int a, b;
        cin >> opt >> a >> b;
        if (opt == "?") {
            if (UF.is_same_set(a, b)) {
                cout << "yes" << "\n";
            } else {
                cout << "no" << "\n";
            }
        } else if (opt == "=") {
            UF.union_set(a, b);
        }
    }

    return 0;
}