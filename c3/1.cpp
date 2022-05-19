#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

namespace numbers
{
    class complex
    {
    private:
        double re_;
        double im_;
    public:
        complex(double re = 0.0, double im = 0.0) : re_(re), im_(im) {};
        explicit complex(const std::string &str) {
            sscanf(str.c_str(), "(%lf,%lf)", &re_, &im_);
        }
        double re() const {
            return re_;
        }
        double im() const {
            return im_;
        }
        double abs2() const {
            return re_ * re_ + im_ * im_;
        }
        double abs() const {
            return sqrt(abs2());
        }
        std::string to_string() const {
            std::ostringstream str;
            str << '(' << std::setprecision(10) << re_ << ',' << im_ << ')';
            return str.str();
        }
        complex& operator+=(const complex &rhs) {
            re_ += rhs.re_;
            im_ += rhs.im_;
            return *this;
        }
        complex& operator-=(const complex &rhs) {
            re_ -= rhs.re_;
            im_ -= rhs.im_;
            return *this;
        }
        complex& operator*=(const complex &rhs) {
            double re_tmp = re_ * rhs.re_ - im_ * rhs.im_;
            double im_tmp = re_ * rhs.im_ + im_ * rhs.re_;
            re_ = re_tmp;
            im_ = im_tmp;
            return *this;
        }
        complex& operator/=(const complex &rhs) {
            double re_tmp = (re_ * rhs.re_ + im_ * rhs.im_) / rhs.abs2();
            double im_tmp = (rhs.re_ * im_ - re_ * rhs.im_) / rhs.abs2();
            re_ = re_tmp;
            im_ = im_tmp;
            return *this;
        }
        complex operator~() const {
            return complex(re_, -im_);
        }
        complex operator-() const {
            return complex(-re_, -im_);
        }
    };
    complex operator+(complex lhs, complex rhs) {
        lhs += rhs;
        return lhs;
    }
    complex operator-(complex lhs, complex rhs) {
        lhs -= rhs;
        return lhs;
    }
    complex operator/(complex lhs, complex rhs) {
        lhs /= rhs;
        return lhs;
    }
    complex operator*(complex lhs, complex rhs) {
        lhs *= rhs;
        return lhs;
    }
}