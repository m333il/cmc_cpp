#include <iostream>
#include <map>
#include <utility>

int main() {
    std::map<std::string, std::pair<int, int>> data;
    std::string surname;
    while (std::cin >> surname) {
        int mark;
        std::cin >> mark;
        data[surname].first += mark;
        ++data[surname].second;
    }
    for (const auto &man : data) {
        std::cout << man.first << " " << man.second.first * 1.0 / man.second.second << std::endl;
    }
}