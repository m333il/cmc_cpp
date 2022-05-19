#include <vector>
#include <map>
#include <functional>
#include <algorithm>

namespace numbers
{
    std::map<std::string, std::function<void(complex_stack&)>> functions = {
        {"+", [](complex_stack &stack) {
                    complex z1 = +stack;
                    stack = ~stack;
                    complex z2 = +stack;
                    stack = ~stack;
                    stack = stack << (z2 + z1);
                }
        }, 
        {"-", [](complex_stack &stack) {
                    complex z1 = +stack;
                    stack = ~stack;
                    complex z2 = +stack;
                    stack = ~stack;
                    stack = stack << (z2 - z1);
                }
        }, 
        {"/", [](complex_stack &stack) {
                    complex z1 = +stack;
                    stack = ~stack;
                    complex z2 = +stack;
                    stack = ~stack;
                    stack = stack << (z2 / z1);
                }
        }, 
        {"*", [](complex_stack &stack) {
                    complex z1 = +stack;
                    stack = ~stack;
                    complex z2 = +stack;
                    stack = ~stack;
                    stack = stack << (z2 * z1);
                }
        }, 
        {"!", [](complex_stack &stack) {
                    stack = stack << +stack;
                }
        }, 
        {";", [](complex_stack &stack) {
                    stack = ~stack;
                }
        }, 
        {"~", [](complex_stack &stack) {
                    complex z = +stack;
                    stack = ~stack;
                    stack = stack << ~z;
                }
        }, 
        {"#", [](complex_stack &stack) {
                    complex z = +stack;
                    stack = ~stack;
                    stack = stack << -z;
                }
        },
    };

    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack stack;
        for (const std::string &arg : args) {
            if (functions.count(arg)) {
                functions[arg](stack);
            } else if (arg == "z") {
                stack = stack << z;
            } else {
                stack = stack << complex(arg);
            }
        }
        return +stack;
    }
}