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

    int n;
    cin >> n;
    while (n--) {
        int P, C;
        cin >> P >> C;
        vector<int> prod;
        vector<int> cons;
        if (P == 0) prod.push_back(0);
        while(P--) {
            int i;
            cin >> i;
            prod.push_back(i);
        }
        while(C--) {
            int i;
            cin >> i;
            cons.push_back(i);
        }
        int min_price = 0;
        int min_ppl = prod.size();
        sort(prod.begin(), prod.end());
        sort(cons.begin(), cons.end());
        for (int i = prod.size() - 1; i >= 0; i--) {
            auto it = lower_bound(cons.begin(), cons.end(), prod[i]);
            int angry = (it - cons.begin()) + (prod.size() - 1 - i);
            if (angry == min_ppl && prod[i] < min_price) {
                min_price = prod[i];
            } else if (angry < min_ppl) {
                min_ppl = angry;
                min_price = prod[i];
            }
        }
        for (int i = 0; i < cons.size(); i++) {
            auto it = lower_bound(prod.begin(), prod.end(), cons[i]);
            int angry = i;
            if (it == prod.begin()) {
                if ( prod[0] > cons[i]) {
                    angry += prod.size();
                } else {
                    angry += prod.size() - 1;
                }
            } else {
                if (prod[it - prod.begin()] != cons[i]) it--;
                int j = prod.size() - 1 - (it - prod.begin());
                if (j == -1 ) j = 0;
                angry += j;
            }
            if (angry == min_ppl && cons[i] < min_price) {
                min_price = cons[i];
            } else if (angry < min_ppl) {
                min_ppl = angry;
                min_price = cons[i];
            }
        }
        cout << min_price << " " << min_ppl << "\n";
    }

    return 0;
}