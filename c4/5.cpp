#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>

int main() {
    std::string str;
    std::getline(std::cin, str);
    str.erase(str.find_last_not_of(" \n\r\t") + 1);
    int n = str.length();
    const char *s = str.c_str();
    std::vector<std::pair<const char*,int>> suffixes(n);
    for (int i = 0; i < n; ++i) {
        suffixes[i].first = s + i;
        suffixes[i].second = i;
    }

    std::sort(suffixes.begin(), suffixes.end(), 
            [](const std::pair<const char*, int> &a, const std::pair<const char*, int> &b) {
                return strcmp(a.first, b.first) < 0;
            });

    for (int i = 0; i < n; ++i) {
        std::cout << suffixes[i].second << std::endl;
    }

    return 0;
}