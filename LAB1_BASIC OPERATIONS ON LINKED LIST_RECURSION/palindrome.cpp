#include <iostream>
using namespace std;

bool isPalindrome(const string &str, int left, int right) // const là để không đổi chuỗi gốc
// &str là để truyền tham chiếu, tránh copy chuỗi lớn
{
    if (left >= right)
    {
        return true;
    }
    if (str[left] != str[right])
    {
        return false;
    }
    return isPalindrome(str, left + 1, right - 1);
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    if (isPalindrome(input, 0, input.length() - 1))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}