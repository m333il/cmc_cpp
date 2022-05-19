#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::abs;

int main() {
    int m, n;
    cin >> m >> n;
    int r1, c1, r2, c2;
    while (cin >> r1 >> c1 >> r2 >> c2) {
        int ans = 0;
        ans += min(abs(r1 - r2), m - abs(r1 - r2));
        ans += min(abs(c1 - c2), n - abs(c1 - c2));
        cout << ans << endl;
    }
    return 0;
}