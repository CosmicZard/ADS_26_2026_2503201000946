#include <iostream>
using namespace std;

void callByValue(int x)
{
    x = 100;
    cout << "Inside Call By Value: " << x << endl;
}
void callByReference(int &x)
{
    x = 200;
    cout << "Inside Call By Reference: " << x << endl;
}
void callByAddress(int *x)
{
    *x = 300;
    cout << "Inside Call By Address: " << *x << endl;
}

int main()
{
    int a = 10;
    cout << "Original value: " << a << endl;
    callByValue(a);
    cout << "After Call By Value: " << a << endl;
    callByReference(a);
    cout << "After Call By Reference: " << a << endl;
    callByAddress(&a);
    cout << "After Call By Address: " << a << endl;
    return 0;
}
