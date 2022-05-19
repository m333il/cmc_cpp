#include <iostream>
using std::string;
using std::hex;
using std::cin;
using std::cout;

int main() {
    char curr, prev;
    cin.get(prev);
    if (cin.eof()) {
        return 0;
    }
    unsigned curr_amount = 1;

    while (cin.get(curr) && !cin.eof()) {
        if (curr == prev) {
            ++curr_amount;
        } else if (curr_amount <= 4 && prev != '#') {
            cout << string(curr_amount, prev);
            curr_amount = 1;
            prev = curr;
        } else {
            cout << '#' << prev << hex << curr_amount << '#';
            curr_amount = 1;
            prev = curr;
        }
    }
    if (curr_amount <= 4 && prev != '#') {
        cout << string(curr_amount, prev);
    } else {
        cout << '#' << prev << hex << curr_amount << '#';
    }
    return 0;
}