#include <iterator>
#include <algorithm>
#include <functional>

template<typename RandomIt, typename Compare>
void selection_sort(RandomIt first, RandomIt last, Compare comp) {
    for (RandomIt curr = first; curr != last; ++curr) {
        auto min = curr;
        auto next = curr + 1;
        while (next != last) {
            if (comp(*next, *min)) {
                min = next;
            }
            ++next;
        }
        if (min != curr) {
            std::iter_swap(min, curr);
        }
    }
}

template<typename RandomIt>
void selection_sort(RandomIt first, RandomIt last) {
    for (RandomIt curr = first; curr != last; ++curr) {
        auto min = curr;
        auto next = curr + 1;
        while (next != last) {
            if (*next < *min) {
                min = next;
            }
            ++next;
        }
        if (min != curr) {
            std::iter_swap(min, curr);
        }
    }
}