#include <iostream>

bool check(const std::string &str) {
    if (str[0] == '3' || str[0] == '4') {
        bool first_part = true;
        for (uint32_t i = 1; i < str.length(); ++i) {
            if (first_part) {
                if (str[i] == '1' || str[i] == '2') {
                    first_part = false;
                } else if (str[i] != '3' && str[i] != '4') {
                    return false;
                }
            } else {
                if (str[i] != '1' && str[i] != '2') {
                    return false;
                }
            }
        }
        return true;
    } else if (str[0] == '1' || str[0] == '2') {
        for (uint32_t i = 1; i < str.length(); ++i) {
            if (str[i] != '1' && str[i] != '2') {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    }
}