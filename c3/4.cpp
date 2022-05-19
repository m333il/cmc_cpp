#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char *argv[]) {
    numbers::complex c(argv[1]);
    double r = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    std::vector<std::string> args;
    for (int i = 4; i < argc; ++i) {
        args.push_back(argv[i]);
    }
    double dphi = 2 * M_PI / n;
    double arg = 0;
    numbers::complex ans(0, 0);

    for (int i = 0; i < n; ++i) {
        numbers::complex z0(r * cos(arg), r * sin(arg));
        numbers::complex z1(r * cos(arg + dphi), r * sin(arg + dphi));
        numbers::complex z = (z1 + z0) / 2.0;
        ans += numbers::eval(args, z + c) * dphi * numbers::complex(0, 1) * z;
        arg += dphi;
    }

    std::cout << ans.to_string() << std::endl;
}