template<typename T>
auto process(const T &c) {
    typename T::value_type sum{};
    int i = 0;
    auto it = c.rbegin();
    while (it != c.rend() && i < 3) {
        sum += *it;
        ++it;
        if (it == c.rend()) {
            break;
        }
        ++it;
        ++i;
    }
    return sum;
}