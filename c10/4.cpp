#include <iostream>

void print_word(int n, int m) {
    for (int i = 0; i < n; ++i) {
        putchar('a');
    }
    for (int i = 0; i < m; ++i) {
        putchar('b');
    }
    for (int i = 0; i < m; ++i) {
        putchar('c');
    }
    for (int i = 0; i < n; ++i) {
        putchar('d');
    }
    putchar('\n');
}

void generate(int n, int m) {
    if (!m || !n) {
        return;
    }
    print_word(n, m);
    generate(n - 1, m + 1);
}

int main() {
    int k;
    std::cin >> k;
    if (k >= 4 && k % 2 == 0) {
        generate(k / 2 - 1, 1);
    }
}