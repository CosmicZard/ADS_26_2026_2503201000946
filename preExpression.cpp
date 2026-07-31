#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0)
        {
            cout << "Error: Division by zero!" << endl;
            exit(1);
        }
        return a / b;
    case '^': return pow(a, b);
    }
    return 0;
}

double evalPrefix(string prefix)
{
    stack<double> st;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (isspace(ch))
            continue;

        if (isalnum(ch))
        {
            st.push(ch - '0');
        }
        else if (isOperator(ch))
        {
            if (st.size() < 2)
            {
                cout << "Error: Invalid prefix expression!" << endl;
                exit(1);
            }
            double op1 = st.top(); st.pop();
            double op2 = st.top(); st.pop();
            double result = applyOp(op1, op2, ch);
            st.push(result);
        }
    }

    if (st.size() != 1)
    {
        cout << "Error: Invalid prefix expression!" << endl;
        exit(1);
    }

    return st.top();
}

int main()
{
    string prefix;
    cout << "Enter prefix expression ";
    cin >> prefix;

    double result = evalPrefix(prefix);
    cout << "Evaluated result " << result << endl;

    return 0;
}