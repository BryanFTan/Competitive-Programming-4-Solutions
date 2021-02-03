#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

map<int, tuple<int, int, double>> shields;

double calc_x(double h, double dest_x, double dest_y) {
    double x = 0.0;
    double non_shield_y = dest_y;
    for (auto it = shields.begin(); it != shields.end(); it++) {
        double l = it->first;
        double u = get<1>(it->second);
        double f = get<2>(it->second);
        non_shield_y -= u - l;
        x += (u - l) * (h * f);
    }
    x += non_shield_y * h;
    return x;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const double EPSILON = 1e-6;

    double x, y, n;
    cin >> x >> y >> n;
    while(n--) {
        double l, u, f;
        cin >> l >> u >> f;
        shields[l] = make_tuple(l, u, f);
    }

    double low, high;
    low = 0.0;
    high = abs(x);
    double mid = high;
    while(high - low > EPSILON) {
        mid = (low + high) / 2;
        if (fabs(calc_x(mid, x, y) - x) < 1e-9 ) {
            break;
        } else if (calc_x(mid, x, y) > abs(x)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    if (x < 0) mid *= -1;
    cout << fixed << setprecision(7) << mid << "\n";

    return 0;
}
