/*
- drawers are disjoint sets
- use size[i] to show available empty drawers for set with element i
- decrement size[i] whenever you union
*/
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
        size[i]--;
        num_sets--;
    }

    int count_sets() {
        return num_sets;
    }

    int get_set_size(int i) {
        i = find_set(i);
        return size[i];
    }
};

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    UnionFind UF(L + 1);
    while (N--) {
        int a, b;
        cin >> a >> b;
        if (UF.get_set_size(a) > 0 || UF.get_set_size(b) > 0) {
            UF.union_set(a, b);
            cout << "LADICA" << "\n";
        } else {
            cout << "SMECE" << "\n";
        }
    }

    return 0;
}