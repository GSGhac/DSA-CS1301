#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> stack;

    for (char c : infix) {
        if (std::isalnum(c))
            postfix += c;
        else if (c == '(')
            stack.push(c);
        else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Pop the '('
        } else if (isOperator(c)) {
            while (!stack.empty() && precedence(c) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    std::string infix = "A+B*C-(D/E)";
    std::string postfix = infixToPostfix(infix);
    std::cout << "Infix: " << infix << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;
    return 0;
}
