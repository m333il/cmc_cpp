#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main() {
    using namespace boost::gregorian;
    uint64_t res = 0;
    char c;
    int y, m, d;
    std::cin >> y >> c >> m >> c >> d;
    date prev(y, m, d);
    while (std::cin >> y >> c >> m >> c >> d) {
        date curr(y, m, d);
        date_duration curr_difference = curr - prev;
        res += abs(curr_difference.days());
        prev = curr;
    }  
    std::cout << res << std::endl;
}