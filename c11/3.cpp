#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

bool check(std::map<std::pair<std::string, char>, std::string> &rules, std::set<std::string> &terminal_states,
        std::string &curr_state, std::string &input, unsigned &symbols, bool last_check) {
    if (symbols == input.length()) {
        return terminal_states.find(curr_state) != terminal_states.end();
    }
    if (!last_check) {
        return false;
    }
    if (rules.count({curr_state, input[symbols]}) == 0) {
        return false;
    }
    curr_state = rules[{curr_state, input[symbols++]}];
    return check(rules, terminal_states, curr_state, input, symbols, true);
}

int main() {
    std::map<std::pair<std::string, char>, std::string> rules;
    std::string left, right;
    char symbol;
    std::cin >> left;
    while (left != "END") {
        std::cin >> symbol >> right;
        rules[{left, symbol}] = right;
        std::cin >> left;
    }
    std::set<std::string> terminal_states;
    std::string state;
    std::cin >> state;
    while (state != "END") {
        terminal_states.insert(state);
        std::cin >> state;
    }
    std::string start_state, input;
    std::cin >> start_state >> input;

    unsigned symbols_amount = 0;
    std::cout << check(rules, terminal_states, start_state, input, symbols_amount, true) << std::endl;
    std::cout << symbols_amount << std::endl << start_state << std::endl;

}
