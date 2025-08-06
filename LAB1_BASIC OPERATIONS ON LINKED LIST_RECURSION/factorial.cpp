#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Please enter a number to cal its factorial: ";
    cin >> n;
    int result = factorial(n);
    cout << "The result is: " << result << endl;
    return 0;
}
