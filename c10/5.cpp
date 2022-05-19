#include <iostream>
#include <string>

bool is_only_terminal(const std::string &str) {
    for (unsigned i = 0; i < str.length(); ++i) {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= '0' && str[i] <= '9')) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string left, right;
    bool is_empty = true;
    bool has_terminal_rule = false;
    bool has_purpose_rule = false;
    bool is_not_decreasing = true;
    bool is_context_free = true;
    bool has_empty_rule = false;
    bool has_purpose_in_right_rule = false;

    while (std::cin >> left >> right) {
        is_empty = false;
        if (is_only_terminal(left)) {
            has_terminal_rule = true;
            break;
        }
        if (left == "S") {
            has_purpose_rule = true;
        }
        if (left.length() > right.length()) {
            is_not_decreasing = false;
        }
        if (left.length() > 1) {
            is_context_free = false;
        }

        if (right == "_") {
            if (left == "S") {
                has_empty_rule = true;
            } else {
                is_not_decreasing = false;
            }
        }
        if (right.find('S') != std::string::npos) {
            has_purpose_in_right_rule = true;
        }
    }
    int ans;
    if (is_empty || has_terminal_rule || !has_purpose_rule) {
        ans = -1;
    } else if (is_context_free) {
        if (is_not_decreasing && (!has_empty_rule || (has_empty_rule && !has_purpose_in_right_rule))) {
            ans = 23;
        } else {
            ans = 2;
        }
    } else {
        ans = 10;
    }
    std::cout << ans << std::endl;

}
