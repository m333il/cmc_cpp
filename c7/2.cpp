template<typename T, typename Func>
T myfilter(const T &c, Func pred) {
    T new_cont;
    for (auto it = c.begin(); it != c.end(); ++it) {
        if (pred(*it)) {
            new_cont.insert(new_cont.end(), *it);
        }
    }
    return new_cont;
}