#include <iostream>
#include <stack>

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main() {
    std::stack<std::string> st;
    char c = getchar();
    while (c != EOF && !isspace(c)) {
        if (is_op(c)) {
            std::string left, right;
            right = st.top();
            st.pop();
            left = st.top();
            st.pop();
            st.push("(" + left + c + right + ")");
        } else {
            st.push(std::string(1, c));
        }
        c = getchar();
    } 
    std::cout << st.top() << std::endl; 
}