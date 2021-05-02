/*
- This classic binary search assumes that list is sorted in ascending order
- In unsorted list, element cannot be found when it's value is smaller than mid but placed to the right of mid
    - vice versa for value is bigger and placed to the left
    - this is because in ascending order, if value smaller than mid we look left, but in fact the position is right
- Do this check for all n elements
*/

#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, c;
    long long x;
    cin >> n >> m >> a >> c >> x;
    vector<int> arr(n);

    //generate all xi
    for (int i = 0; i < n; i++) {
        x = (a * x + c) % m;
        arr[i] = (int) x;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        bool canFind = true;
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + ((right - left)/2);
            if (arr[mid] == arr[i]) break;
            if ((i < mid && arr[i] > arr[mid]) || (i > mid && arr[i] < arr[mid])) { //check if can be found
                canFind = false;
                break;
            }
            if (arr[i] > arr[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (canFind) count++;
    }

    cout << count << "\n";

    return 0;
}