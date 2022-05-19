#include <iostream>

class Result
{  
public: 
    int64_t result;
};

void func(int64_t m, int64_t n) {
    try {
        Result f{};
        if (m == 0) {
            f.result = n + 1;
        } else if (n == 0) {
            func(m - 1, 1);
        } else {
            func(m, n - 1);
        }
        throw f;
    } catch (Result f) {
        if (m > 0 && n > 0) {
            func(m - 1, f.result);
        } else {
            throw f;
        }
    }
}

int main() {
    int64_t m, n;
    while (std::cin >> m >> n) {
        try {
            func(m, n);
        } catch (Result f) {
            std::cout << f.result << std::endl;
        }
    }
}