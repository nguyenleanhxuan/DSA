#include <iostream>
using namespace std;

int countTriangles(int m, int n) {
    int sum = (n + 1) * (n + 2) / 2;
    return sum * (m + 1);
}

int main() {
    int m, n;
    cout << "Nhap số đường thẳng từ A cắt BC: ";
    cin >> n;
    cout << "Nhap số đường thẳng song song BC: ";
    cin >> m;

    int result = countTriangles(m, n);
    cout << "So tam giac tao thanh: " << result << endl;

    return 0;
}
