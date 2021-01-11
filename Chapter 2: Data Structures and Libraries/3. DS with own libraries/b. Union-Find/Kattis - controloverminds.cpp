/*
- Use a hashmap: unordered_map<set key, seen in M>
- If seen in M != set size, set M cannot be formed
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
        num_sets--;
    }

    int count_sets() {
        return num_sets;
    }

    int set_size(int i) {
        i = find_set(i);
        return size[i];
    }
};

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    UnionFind UF(500001);
    int count = 0;
    int N, M;
    cin >> N;
    while(N--) {
        cin >> M;
        int m = M;
        unordered_map<int, int> same_set;
        vector<int> arr;
        bool good = true;
        while(M--) {
            int i;
            cin >> i;
            arr.push_back(i);
            same_set[UF.find_set(i)]++;
        }
        for (auto it : same_set) {
            if (UF.set_size(it.first) != it.second) {
                good = false;
                break;
            }
        }
        if (good) {
            count++;
            for (int i = 1; i < m; i++) {
                UF.union_set(arr[i - 1], arr[i]);
            }
        }
    }
    cout << count << "\n";

    return 0;
}