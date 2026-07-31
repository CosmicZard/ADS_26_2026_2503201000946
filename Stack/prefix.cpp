#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int prefix(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return -1; 
    }
}

string infToPre(string infix) {
    string postfix = "";
    stack<char> st;
    reverse(infix.begin(), infix.end());
    for (char ch : infix) {
        if (isalnum(ch
        )) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); 
        } else {
            while (!st.empty() && prefix(st.top()) >= prefix(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    return postfix;
}

int main() {
    
    string infix = "A+(B*C-(D/E^F)*G)*H";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infToPre(infix) << endl;


    return 0;
}