#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;
    float marks;

public:
    void inputInfo()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter marks: ";
        cin >> marks;
    }
    void displayInfo()
    {
        cout << "-------Student Information:---------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    Student s1;
    s1.inputInfo();
    s1.displayInfo();
    return 0;
}