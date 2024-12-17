#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <cctype>

using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            // If operand, add to postfix expression
            postfix += c;
        } else if (c == '(') {
            // If '(', push onto stack
            st.push(c);
        } else if (c == ')') {
            // If ')', pop and add to postfix until '(' is found
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        } else if (isOperator(c)) {
            // If operator, pop operators with higher/equal precedence and then push
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix, map<char, int> &values) {
    stack<int> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            // If operand, push its value onto the stack
            st.push(values[c]);
        } else if (isOperator(c)) {
            // If operator, pop two elements and perform the operation
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    return st.top(); // Final result
}

// Main function with menu-driven interface
int main() {
    string infix, postfix;
    map<char, int> values; // To store variable values
    int choice;

    do {
        cout << "\nMenu:";
        cout << "\n1. Convert Infix to Postfix";
        cout << "\n2. Set Values for Variables";
        cout << "\n3. Evaluate Postfix Expression";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter Infix Expression: ";
                cin >> infix;
                postfix = infixToPostfix(infix);
                cout << "Postfix Expression: " << postfix << endl;
                break;
            }
            case 2: {
                cout << "Enter values for variables used in the expression (e.g., a=5):" << endl;
                for (char c : postfix) {
                    if (isalnum(c) && values.find(c) == values.end()) {
                        int val;
                        cout << c << " = ";
                        cin >> val;
                        values[c] = val;
                    }
                }
                break;
            }
            case 3: {
                if (postfix.empty()) {
                    cout << "Convert infix to postfix first!" << endl;
                } else {
                    int result = evaluatePostfix(postfix, values);
                    cout << "Result of Postfix Evaluation: " << result << endl;
                }
                break;
            }
            case 4: {
                cout << "Exiting program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
