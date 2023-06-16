#include <stack>
#include <iostream>

using namespace std;

class Stack {
private:
    int top;
public:
    string a[100];
    Stack() { top = -1; }
    bool push(string g) {
        if (top >= (100 - 1)) {
            cout << "Stack Overflow";
            return false;
        }
        else {
            top++;
            if (top < 100) {
                a[top] = g;
                cout << g << " pushed into stack\n";
                return true;
            }
            else {
                top--;
                return false;
            }
        }
    }

    int size() {
        return top + 1;
    }
    string pop() {
        if (top < 0)
        {
            cout << "Stack Underflow";
            return "";
        }
        else
        {
            string x = a[top--];
            return x;
        }
    }
    string getTop() {
        if (top < 0) {
            return "";
        }
        return a[top];
    }
    bool empty() {
        return (top < 0);
    }
};

bool isBalanced(string expr) {
    Stack st;
    int count = 0;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(string(1, c));
            count++;
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return false;
            }
            string top = st.getTop();
            st.pop();
            count--;
            if ((c == ')' && top != "(") || (c == ']' && top != "[") || (c == '}' && top != "{")) {
                return false;
            }
        }
    }
    return count == 0;
}


int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '^') {
        return 3;
    }
    else {
        return -1;
    }
}

string infixToPrefix(string expr) {
    stack<char> opStack;
    stack<string> valStack;

    int openParenCount = 0;
    int closeParenCount = 0;

    for (int i = static_cast<int>(expr.length() - 1); i >= 0; i--) {
        char c = expr[i];
        if (c == ' ') {
            continue;
        }
        else if (isdigit(c) || isalpha(c)) {
            string operand(1, c);
            valStack.push(operand);
        }
        else if (c == ')') {
            opStack.push(c);
            closeParenCount++;
        }
        else if (c == '(') {
            opStack.push(c);
            openParenCount++;
        }
        else {
            while (!opStack.empty() && precedence(opStack.top()) > precedence(c)) {
                string val1 = valStack.top();
                valStack.pop();
                string val2 = valStack.top();
                valStack.pop();
                char op = opStack.top();
                opStack.pop();
                string prefix = string(1, op) + val1 + val2;
                valStack.push(prefix);
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        string val1 = valStack.top();
        valStack.pop();
        string val2 = valStack.top();
        valStack.pop();
        char op = opStack.top();
        opStack.pop();
        string prefix = string(1, op) + val1 + val2;
        valStack.push(prefix);
    }

    if (openParenCount != closeParenCount) {
        throw invalid_argument("Unbalanced parentheses in expression");
    }

    return valStack.top();
}
