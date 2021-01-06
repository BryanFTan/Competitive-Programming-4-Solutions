/*
- In 3-dimension cube (N = 3), can use 3 bits to represent x, y, z coordinates. 000 ... 111 are corners on the cube
- Neighbours of 000 are 001, 010, 100
- Neighbours of 001 are 000, 011, 101
- Therefore can get neighbours by flipping each bit one by one
    - flipping can be done by S ^= (1 << j)
- Collate the weights in a array and then collate potencies in another array
- Iterate through to find max pair potentcy
*/
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

    int N;
    while(cin >> N) {
        vector<int> weights;
        for (int corner = 0; corner < (1 << N); corner++) {
            int weight;
            cin >> weight;
            weights.push_back(weight);
        }

        vector<int> potencies;
        for (int corner = 0; corner < (1 << N); corner++) {
            int potency = 0;
            for (int bit = 0; bit < N; bit++) {
                potency += weights[corner ^ (1 << bit)];
            }
            potencies.push_back(potency);
        }

        int maxPotency = 0;
        for (int corner = 0; corner < (1 << N); corner++) {
            for (int bit = 0; bit < N; bit++) {
                maxPotency = max(maxPotency, potencies[corner] + potencies[corner ^ (1 << bit)]);
            }
        }
        cout << maxPotency << "\n";
    }

    return 0;
}