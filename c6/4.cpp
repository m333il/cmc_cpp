#include <iostream>
#include <utility>
#include <map>

constexpr unsigned MOD = 4294967161;

int main() {
    std::map<std::pair<uint64_t, uint64_t>, uint64_t> matrix;
    uint64_t r, c, v;
    
    while (std::cin >> r >> c >> v) {
        if (r != 0 || c != 0 || v != MOD) {
            matrix[{r, c}] += v;
            matrix[{r, c}] %= MOD;
        }
    }
    for (const auto &el : matrix) {
        if (el.second) {
            std::cout << el.first.first << " " << el.first.second << " " << el.second << std::endl;
        }
    }
}