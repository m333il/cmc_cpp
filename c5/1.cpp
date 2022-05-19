#include <vector>
#include <cstdint>

void process(const std::vector<uint64_t> &a, std::vector<uint64_t> &b, int step) {
    auto it_b = b.rbegin();
    for (auto it_a = a.begin(); it_a < a.end() && it_b < b.rend(); it_a += step, ++it_b) {
        *it_b += *it_a;
    }
}