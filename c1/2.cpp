#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class A {
private:
    int a;
    bool output_flag = false;
public:
    A() {
        cin >> a;
    }
    A(const A &t) {
        cin >> a;
        a += t.get();
        output_flag = true;
    }
    ~A() {
        if (output_flag) {
            cout << a << endl;
        }
    }
    int get() const {
        return a;
    }
};