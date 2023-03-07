#include <iostream>
using namespace std;

template <typename T>
T swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    template <typename T>
    T a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}