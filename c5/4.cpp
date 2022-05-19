#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Functor
{
    double sum = 0;
    int amount = 0;
    void operator() (double value) {
        sum += value;
        ++amount;
    }
    double mean() const {
        return sum / amount;
    }
};

int main() {
    std::vector<double> series;
    double x;
    while (std::cin >> x) {
        series.push_back(x);
    }

    double delta = static_cast<int>(series.size() * 0.1);
    sort(series.begin() + delta, series.end() - delta);
    delta = static_cast<int>((series.size() - 2 * delta) * 0.1 + delta);
    Functor f;
    double mean = for_each(series.begin() + delta, series.end() - delta, f).mean();
    
    std::cout << std::fixed << std::setprecision(10) << mean << std::endl;
}
