#include <iostream>

class S {
public:
    int ans = 0;
    enum States
    {
        END_READING,
        EMPTY_READING,
        READING,
    };
    States state = READING;
    S() {
        if (!(std::cin >> ans)) {
            state = EMPTY_READING;
        }
    }
    S(const S &v) {
        int curr;
        if (std::cin >> curr) {
            ans = v.ans + curr;
        } else {
            ans = v.ans;
            state = END_READING;
        }
    }
    ~S() {
        if (state == END_READING) {
            std::cout << ans << std::endl;
        }
    }

    operator bool() const {
        return state == READING;
    }
};