#include <iostream>
#include <utility>
#include <vector>
#include <map>

constexpr unsigned MOD = 4294967161;

int main() {
    std::map<std::pair<uint64_t, uint64_t>, uint64_t> matrix1, matrix3;
    std::map<uint64_t, std::vector<std::pair<uint64_t, uint64_t>>> matrix2;
    uint64_t r, c, v;
    std::cin >> r >> c >> v;
    while (r != 0 || c != 0 || v != MOD) {
        matrix1[{r, c}] = v;
        std::cin >> r >> c >> v;
    }
    while (std::cin >> r >> c >> v) {
        matrix2[r].push_back({c, v});
    }
    
    for (const auto &el1 : matrix1) {
        for (const auto &el2 : matrix2[el1.first.second]) {
            matrix3[{el1.first.first, el2.first}] += el1.second * el2.second;
            matrix3[{el1.first.first, el2.first}] %= MOD;
        }
    }
    

    for (const auto &el : matrix3) {
        if (el.second) {
            std::cout << el.first.first << " " << el.first.second << " " << el.second << std::endl;
        }
    }
}
