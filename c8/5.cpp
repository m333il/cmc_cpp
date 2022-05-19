#include <complex>
#include <array>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>

namespace Equations
{
    template <typename K>
    std::pair<bool, std::vector<std::complex<K>>> quadratic(const std::array<std::complex<K>, 3> &v) {
        auto a = v[2];
        auto b = v[1];
        auto c = v[0];
        if (!std::norm(a)) {
            if (!std::norm(b)) {
                return std::make_pair(std::norm(c), std::vector<std::complex<K>>());
            } else {
                return std::make_pair(true, std::vector<std::complex<K>>{-c / b});
            }
        }
        auto d = sqrt(b * b - static_cast<std::complex<K>>(4.0) * a * c);
        auto x1 = (-b + d) / static_cast<std::complex<K>>(2.0) / a;
        auto x2 = (-b - d) / static_cast<std::complex<K>>(2.0) / a;
        return std::make_pair(true, std::vector<std::complex<K>>{x1, x2});
    }  
}