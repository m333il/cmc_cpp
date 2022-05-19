#include <iostream>

int main() {
    bool num_flag = false;
    bool zero_flag = false;
    char curr;
    while ((curr = getchar()) != EOF) {
        if (curr > '0' && curr <= '9') {
            putchar(curr);
            zero_flag = false;
            num_flag = true;
        } else if (curr == '0') {
            if (!num_flag) {
                zero_flag = true;
            }
            if (!zero_flag) {
                putchar(curr);
            }
        } else {
            if (zero_flag) {
                putchar('0');
            }
            num_flag = false;
            zero_flag = false;
            putchar(curr);
        }
    }
    if (zero_flag) {
        putchar('0');
    }
    return 0;
}