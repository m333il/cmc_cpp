#include <vector>
#include <iostream>
#include <algorithm>

void process(const std::vector<int> &v1, std::vector<int> &v2) {
    std::vector<int> indexes = v1;
    std::sort(indexes.begin(), indexes.end());
    auto unique_last = std::unique(indexes.begin(), indexes.end());
    indexes.erase(unique_last, indexes.end());

    int size = v2.size();
    v2.reserve(2 * size);
    auto it_ind = std::lower_bound(indexes.begin(), indexes.end(), 0);
    
    int curr_ind = 0;
    for (auto it_v2 = v2.begin(); it_v2 != v2.begin() + size; ++it_v2, ++curr_ind) {
        if (it_ind == indexes.end() || curr_ind != *it_ind) {
            v2.push_back(*it_v2);
        } else {
            ++it_ind;
        }
    }

    v2.erase(v2.begin(), v2.begin() + size);
}