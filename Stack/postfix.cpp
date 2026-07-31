#include <iostream>
#include <stack>

using namespace std;

int  postfix(char op) {
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

string infToPost(string infix) {
    string result = "";
    stack<char> st;
    for (char ch : infix) {
        if (isalnum(ch)) {
            result += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        } else {
            while (!st.empty() && postfix(st.top()) >= postfix(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    return result;
}

int main() {
    
    string infix = "A+(B*C-(D/E^F)*G)*H";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infToPost(infix) << endl;

    return 0;
}