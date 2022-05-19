#include <iostream>
#include <string>

using std::string;

class BinaryNumber
{
private:
    string num;
public:
    BinaryNumber(const string &s) {
        num = s;
    }
    operator string () const {
        return num;
    }
    const BinaryNumber &operator++() {
        if (num == "0") {
            num = "1";
            return *this;
        }
        size_t len = num.size();
        while (--len > 0) {
            if (num[len] == '1') {
                num[len] = '0';
            } else {
                num[len] = '1';
                return *this;
            }
        }
        num = "1" + num;
        num[1] = '0';
        return *this;
    }
};