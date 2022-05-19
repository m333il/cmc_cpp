#include <iostream>
#include <list>

void del(std::list<int> &l, int pos) {
    if (static_cast<unsigned>(pos) > l.size()) {
        return;
    }
    auto it = l.begin();
    int i = 1;
    while (i < pos) {
        ++it;
        ++i;
    }
    l.erase(it);
}

void ins(std::list<int> &l, int pos, int el) {
    auto it = l.begin();
    int i = 1;
    while (i < pos && it != l.end()) {
        ++it;
        ++i;
    }
    l.insert(it, el);
}

int main() {
    std::list<int> l;
    int el;
    while (std::cin >> el && el != 0) {
        l.push_back(el);
    }
    int x;
    while (std::cin >> x) {
        if (x > 0) {
            int y;
            std::cin >> y;
            ins(l, x, y);
        } else {
            del(l, -x);
        }
    }
    for (const auto &i : l) {
        std::cout << i << std::endl;
    }
}
    