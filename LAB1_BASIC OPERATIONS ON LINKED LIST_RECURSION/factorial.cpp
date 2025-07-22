#include <iostream>
using namespace std;

int factorial( int n){
    if (n < 0) return -1;
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else {
        return n*factorial(n-1);
    }
}

int main(){
    int num;
    cout << "Enter a number to calculate factorial: ";
	cin >> num;
    int x = factorial(num);
    cout << x;
    return 0;
}