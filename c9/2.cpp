#include <iostream>

class Result
{  
public: 
    int64_t result;
    Result() : result(0) {}
};

void func(int64_t a, int64_t b, int64_t k) {
    try {
        Result f;
        if (k == 0) {
            f.result = a + b;
        } else if (b == 1) {
            f.result = a;
        } else {
            func(a, b - 1, k);
        }
        throw f;
    } catch (Result f) {
        if (b > 1 && k > 0) {
            func(a, f.result, k - 1);
        } else {
            throw f;
        }
    }
}

int main() {
    int64_t a, b, k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result f) {
            std::cout << f.result << std::endl;
        }
    }
}