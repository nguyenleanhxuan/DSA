#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
        return 1;
    return fibo(n - 2) + fibo(n - 1);
}

int main()
{
    int n;
    cout << "Please enter a position to calculate fibo at this: ";
    cin >> n;
    int result = fibo(n - 1);
    cout << "The fibo number at position" << n << "is :" << result << endl;
    return 0;
}
