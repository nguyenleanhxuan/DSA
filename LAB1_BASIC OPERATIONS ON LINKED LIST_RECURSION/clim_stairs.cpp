#include <iostream>
using namespace std;

int climb_stairs(int n)
{
    if (n <= 1)
    {
        return 1; // Base case: 1 way to climb 0 or 1 step
    }
    return climb_stairs(n - 1) + climb_stairs(n - 2); // Recursive case
}

int main()
{
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    cout << "Number of distinct ways to climb " << n << " steps: " << climb_stairs(n) << endl;
    return 0;
}