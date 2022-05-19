class Sum {
private:
    int sum;
public:
    Sum(int a, int b) {
        sum = a + b;
    }
    
    Sum(Sum a, int b) {
        sum = a.get() + b;
    }

    int get() const {
        return sum;
    }
};