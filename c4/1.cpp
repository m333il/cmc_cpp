#include <iostream>
using std::cout;
using std::endl;

class C
{
private:
    int c;
public:
    C(int x) {
        c = x * 2;
    }
    C(const C &l) {
        c = l.c * 2;
    }
    int get() const {
        return c;
    }
    C operator+ (const C &l) {
        return C(c + l.c);
    }
};