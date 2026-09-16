#include <iostream>
using namespace std;

bool isPalindrome(const string& str, int left, int right) {
    if (left >= right)
        return true;

    if (str[left] != str[right])
        return false;

    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    string test1 = "racecar";
    string test2 = "hello";

    cout << "Is '" << test1 << "' a palindrome? "
         << (isPalindrome(test1, 0, test1.length() - 1) ? "Yes" : "No") << endl;

    cout << "Is '" << test2 << "' a palindrome? "
         << (isPalindrome(test2, 0, test2.length() - 1) ? "Yes" : "No") << endl;

    return 0;
}