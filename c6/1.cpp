#include <iostream>
#include <algorithm>
#include <vector>

int count_bits(int x) {
    int ans = 0;
    while (x) {
        ans += x & 1;
        x >>= 1;
    }
    return ans;
}

bool cmp(const int &lhs, const int &rhs) {
    return count_bits(lhs) < count_bits(rhs);
}

int main() {
    std::vector<int> v;
    int x;
    while (std::cin >> x) {
        v.push_back(x);
    }
    std::stable_sort(v.begin(), v.end(), cmp);
    for (const auto &el : v) {
        std::cout << el << std::endl;
    }
}