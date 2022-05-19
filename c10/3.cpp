#include <iostream>

// L = {a^n 0^m b^n 1^m}

bool check(const std::string &str) {
    uint32_t n = 0;
    uint32_t m = 0;
    uint32_t i = 0;
    while (str[i] != '0') {
        if (str[i] == 'a') {
            ++n;
        } else if (str[i] != '0') {
            return false;
        }
        ++i;
    }
    while (str[i] != 'b') {
        if (str[i] == '0') {
            ++m;
        } else if (str[i] != 'b') {
            return false;
        }
        ++i;
    }
    for (uint32_t j = 0; j < n; ++j, ++i) {
        if (str[i] != 'b') {
            return false;
        }
    }
    for (uint32_t j = 0; j < m; ++j, ++i) {
        if (str[i] != '1') {
            return false;
        }
    }
    return str.length() == (m + n) * 2 && m && n;
}

int main() {
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    }
}