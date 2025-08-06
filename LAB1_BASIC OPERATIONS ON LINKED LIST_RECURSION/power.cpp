#include <iostream>
using namespace std;

int power(int x, int m)
{
    if (m == 0)
        return 1;
    else
        return x * power(x, m - 1);
}

int main()
{
    int a, n;
    cin >> a;
    cin >> n;
    if (n < 0)
    {
        float ans = 1.0 / power(a, -n);
        cout << ans << endl;
    }
    else
    {
        int ans = power(a, n);
        cout << ans << endl;
    }
    return 0;
}
