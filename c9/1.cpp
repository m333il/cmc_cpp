#include <iostream>

class C
{
private:
    std::string str;
public:
    C() {
        if (!(std::cin >> str)) {
            throw 1;
        }
    }
    ~C() {
        std::cout << str << std::endl;
    }
};

void read() {
    C c;
    read();
}

int main() {
    try {
        read();
    } catch(int) {

    }
    
    return 0;
}