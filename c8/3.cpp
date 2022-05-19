#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

class Factory
{
private:
    Factory() {}
    Factory(const Factory& other) = delete;
    Factory(Factory&& other) = delete;
    Factory& operator= (const Factory& other) = delete;
    Factory& operator= (Factory&& other) = delete;
public:
    static Factory& factory_instance() {
        static Factory INSTANCE;
        return INSTANCE;
    }
    Figure* new_figure(const std::string& str) {
        std::istringstream input(str);
        std::string params;
        char name;
        input >> name;
        std::getline(input, params);
        if (name == 'R') {
            return Rectangle::make(params);
        } else if (name == 'C') {
            return Circle::make(params);
        } else {
            return Square::make(params);
        }
    }
};

int main() {
    std::vector<Figure*> figures;
    std::string s;
    while (std::getline(std::cin, s)) {
        figures.push_back(Factory::factory_instance().new_figure(s));
    }
    std::stable_sort(figures.begin(), figures.end(), [](const auto &a, const auto &b) 
    {
        return a->get_square() < b->get_square();
    });
    for (auto& fig : figures) {
        std::cout << fig->get_square() << std::endl;
        delete fig;
    }
    return 0;
}