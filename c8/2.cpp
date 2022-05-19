#include <cmath>
#include <sstream>

class Rectangle : Figure
{
private:
    double a;
    double b;
public:
    Rectangle(double a = 0, double b = 0) : a(a), b(b) {}
    double get_square() const {
        return a * b;
    }
    static Rectangle *make(std::string figure) {
        std::istringstream s(figure);
        double a, b;
        s >> a >> b;
        return new Rectangle(a, b);
    }
};

class Square : Figure
{ 
private:
    double a;
public:
    Square(double a = 0) : a(a) {}
    double get_square() const {
        return a * a;
    }
    static Square *make(std::string figure) {
        std::istringstream s(figure);
        double a;
        s >> a;
        return new Square(a);
    }
};

class Circle : Figure
{
private:
    double r;
public:
    Circle(double r = 0) : r(r) {}
    double get_square() const {
        return M_PI * r * r;
    }
    static Circle *make(std::string figure) {
        std::istringstream s(figure);
        double r;
        s >> r;
        return new Circle(r);
    }
};