#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXSIZE 5

int st[MAXSIZE];
int top = -1;


bool isOverflow()
{
    return top == MAXSIZE - 1;
}


bool isUnderflow()
{
    return top == -1;
}


void push(int x)
{
    if (isOverflow())
    {
        cout << "Stack is Full!" << endl;
        return;
    }

    top++;
    st[top] = x;
    cout << x << " is pushed." << endl;
}


void pop()
{
    if (isUnderflow())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }

    cout << st[top] << " is popped." << endl;
    top--;
}


void peek()
{
    if (isUnderflow())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }

    cout << "Top element is: " << st[top] << endl;
}


void traverse()
{
    if (isUnderflow())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }

    cout << "Stack elements are: ";

    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << " ";
    }

    cout << endl;
}


int main()
{
    int ch, value;

    do
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                traverse();
                break;

            case 5:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (ch != 5);

    return 0;
}