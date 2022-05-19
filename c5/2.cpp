#include <vector>
#include <cstdint>

void process(std::vector<int64_t> &v, int64_t thres) {
    v.reserve(2 * v.size());
    for (auto it = v.rbegin(); it < v.rend(); ++it) {
        if (*it >= thres) {
            v.push_back(*it);
        }
    }
}