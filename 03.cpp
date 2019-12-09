#include <iostream>


using namespace std;

int fiba(int n) {
    if (n > 2)
        return fiba(n - 1) + fiba(n - 2);
    return 1;
}

int main() {
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << "Fn=" << fiba(n);
    return 0;
}