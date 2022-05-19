#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <string>

void fill(const std::vector<std::pair<char, std::string>> &rules, 
        std::set<char> &attainable_symbols, char c) {
    for (auto it = rules.begin(); it < rules.end(); ++it) {
        if (c == it->first) {
            for (auto curr = it->second.begin(); curr < it->second.end(); ++curr) {
                if (*curr >= 'A' && *curr <= 'Z' && 
                        attainable_symbols.find(*curr) == attainable_symbols.end()) {
                    attainable_symbols.insert(*curr);
                    fill(rules, attainable_symbols, *curr);
                }
            }
        }
    }
}

int main() {
    std::vector<std::pair<char, std::string>> rules;
    char left;
    std::string right;
    while (std::cin >> left >> right) {
        rules.push_back({left, right});
    }

    std::set<char> attainable_symbols{'S'};
    fill(rules, attainable_symbols, 'S');

    for (auto it = rules.begin(); it < rules.end(); ++it) {
        if (attainable_symbols.find(it->first) != attainable_symbols.end()) {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }
}