#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

int main() {
    int amount = 0;
    double curr;
    double sum = 0;
    double quadric_sum = 0;

    while (cin >> curr) {
        ++amount;
        sum += curr;
        quadric_sum += curr * curr;
    }

    double mean = sum / amount;
    double variance = sqrt(quadric_sum / amount - mean * mean);

    cout << setprecision(10) << mean << endl;
    cout << setprecision(10) << variance << endl;

    return 0;
}