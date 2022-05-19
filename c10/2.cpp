#include <iostream>

char check(uint32_t ones, uint32_t zeros, char c) {
    while (c != EOF && !isspace(c)) {
        uint32_t ones_curr = 0;
        uint32_t zeros_curr = 0;
        while (c == '0') {
            ++zeros_curr;
            c = getchar();
        }
        while (c == '1') {
            ++ones_curr;
            c = getchar();
        }
        if (ones_curr != ones || zeros_curr != zeros) {
            std::cout << 0 << std::endl;
            while (c != EOF && !isspace(c)) {
                c = getchar();
            }
            return c;
        }
    }
    std::cout << 1 << std::endl;
    return c;
}

int main() {
    char c = getchar();
    while (isspace(c)) {
        c = getchar();
    }
    while (c != EOF) {
        uint32_t ones = 0;
        uint32_t zeros = 0;
        while (c == '0') {
            ++zeros;
            c = getchar();
        }
        while (c == '1') {
            ++ones;
            c = getchar();
        }
        if (!ones || !zeros) {
            std::cout << 0 << std::endl;
            while (c != EOF && !isspace(c)) {
                c = getchar();
            }
        } else {
            c = check(ones, zeros, c);
        }
        while (isspace(c)) {
            c = getchar();
        }
    }
}