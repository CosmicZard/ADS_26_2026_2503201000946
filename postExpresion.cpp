#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;
    istringstream iss(exp);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            st.push(stoi(token));
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (token[0]) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    
    string expression = "54 6 + 7 4 - * 9 / 35 15 + +";
    
    cout << "Postfix Expression: " << expression << endl;
    cout << "Final Evaluation Result: " << evaluatePostfix(expression) << endl;
    
    return 0;
}