#include <algorithm>
#include <vector>

template<class It_ind, class It_el>
It_el myremove(It_ind index_first, It_ind index_last, It_el first, It_el last) {
    std::vector<int> index(index_first, index_last);
    std::sort(index.begin(), index.end());
    auto non_unique = std::unique(index.begin(), index.end());
    index.erase(non_unique, index.end());

    int size = last - first;
    auto it = lower_bound(index.begin(), index.end(), size);
    index.erase(it, index.end());
    it = lower_bound(index.begin(), index.end(), 0);
    
    int curr_ind = 0;
    It_el curr_it = first;
    while (curr_ind < size) {
        if (it != index.end() && curr_ind == *it) {
            while (it != index.end() && *it == curr_ind) {
                ++it, ++curr_ind, ++curr_it;
            }
        }
        std::iter_swap(first, curr_it);
        ++first, ++curr_it, ++curr_ind;
    }
    return first;     
}