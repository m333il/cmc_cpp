class C
{
private:
    int x;
public:
    int get_x() const {
        return x;
    }
    C() {
        x = 0.0;
    }
    C(int a, int b) {
        x = a + b;
    }
    C(double a) {
        x = a;
    }
    C(const C *c) {
        x = c->x;
    }

    C& operator++() {
        ++x;
        return *this;
    }

};

int operator*(const C &c1, const C *c2) {
    return c1.get_x() * c2->get_x();
}

int operator+(int a, const C &c) {
    return a + c.get_x();
}

int operator~(const C &c) {
    return ~c.get_x();
}