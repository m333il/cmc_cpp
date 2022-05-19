#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::hex;

int main() {
    uint32_t offset;
    while (cin >> hex >> offset) {
        uint32_t curr = 0;
        uint32_t octet = 0;
        for (int i = 0; i < 4; ++i) {
            curr = 0;
            for (int j = 0; j < 4; ++j) {
                if (cin >> hex >> octet) {
                    curr <<= 8;
                    curr |= octet;
                } else {
                    return 0;
                }
            }
            cout << curr << endl;
        }
    }
    return 0;
}