#include <iostream>
using namespace std;

template <typename T>
T largestDataType(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}



int main()
{
    template <typename T>
    T arr[5];
    cout << "Enter 5 elements for the array: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    cout << "The largest element is: " << largestDataType(arr, 5) << endl;
    return 0;
}