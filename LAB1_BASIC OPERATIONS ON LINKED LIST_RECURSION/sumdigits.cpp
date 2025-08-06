#include <iostream>
using namespace std;

int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    int result = sumDigits(n);
    cout << "The sum of the digits is: " << result << endl;
    return 0;
}