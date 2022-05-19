#include <vector>
#include <functional>

template <typename Iter, typename Func>
void myapply(Iter first, Iter last, Func f) {
    for (auto it = first; it != last; ++it) {
        f(*it);
    }
}

template <typename Iter, typename Func>
auto myfilter2(Iter first, Iter last, Func f) {   
    std::vector<std::reference_wrapper<typename std::iterator_traits<Iter>::value_type>> ans;
    for (auto it = first; it != last; ++it) {
        if (f(*it)) {
            ans.push_back(*it);
        }
    }
    return ans;
}