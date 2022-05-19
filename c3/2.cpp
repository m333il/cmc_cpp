#include <iostream>

namespace numbers
{
    class complex_stack {
    private:
        static constexpr size_t default_capacity = 10;
        size_t stack_size;
        size_t capacity;
        complex *top;

    public:
        complex_stack(size_t capacity_ = default_capacity) : stack_size(0), capacity(capacity_), top(nullptr) {
            top = new complex[default_capacity];
        }

        size_t size() const {
            return stack_size;
        }

        void increase_capacity() {
            capacity *= 2;
            complex *new_top = new complex[capacity];
            for (size_t i = 0; i < stack_size; ++i) {
                new_top[i] = top[i];
            }
            delete[] top;
            top = new_top;
        }

        complex_stack& operator=(const complex_stack &other) {
            capacity = other.capacity;
            delete[] top;
            top = new complex[capacity];
            stack_size = other.stack_size;
            for (size_t i = 0; i < stack_size; ++i) {
                top[i] = other.top[i];
            }
            return *this;
        } 

        complex_stack(const complex_stack& st) : stack_size(st.stack_size), capacity(st.capacity), top(nullptr) {
            *this = st;
        }

        ~complex_stack() {
            delete[] top;
        }

        complex operator[] (size_t i) const {
            return top[i];
        }

        complex_stack operator<<(complex number) const {
            complex_stack res = *this;
            if (res.stack_size == res.capacity) {
                res.increase_capacity();
            }
            res.top[res.stack_size++] = number;
            return res;
        }

        complex operator+() const {
            return top[stack_size - 1];
        }

        complex_stack operator~() const {
            complex_stack res = *this;
            --res.stack_size;
            return res;
        }
    };
}