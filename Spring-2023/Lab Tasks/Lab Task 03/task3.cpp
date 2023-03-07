#include <iostream>
using namespace std;

template <typename T>
T findSameElementArray (T arr1[], T arr2[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr1[i] == arr2[j]) {
                return arr1[i];
            }
        }
    }
    return -1;
}

template <typename T>
T concatenateDifferentElementsArray (T arr1[], T arr2[], int size) {
    T arr3[size];
    int counter = 0;
    for (int i = 0; i < size; i++) {
        bool isFound = false;
        for (int j = 0; j < size; j++) {
            if (arr1[i] == arr2[j]) {
                isFound = true;
                break;
            }
        }
        if (!isFound) {
            arr3[counter] = arr1[i];
            counter++;
        }
    }
    for (int i = 0; i < size; i++) {
        bool isFound = false;
        for (int j = 0; j < size; j++) {
            if (arr2[i] == arr1[j]) {
                isFound = true;
                break;
            }
        }
        if (!isFound) {
            arr3[counter] = arr2[i];
            counter++;
        }
    }
    return arr3;
}

int main() {
    template <typename T>
    T arr1[];
    template <typename T>
    T arr2[];
    cout<<"Enter 5 elements for the first array: ";
    for (int i = 0; i < 5; i++) {
        cin>>arr1[i];
    }
    cout<<"Enter 5 elements for the second array: ";
    for (int i = 0; i < 5; i++) {
        cin>>arr2[i];
    }
    cout<<"The same element is: "<<findSameElementArray(arr1, arr2, 5)<<endl;
    cout<<"The concatenated array is: "<<concatenateDifferentElementsArray(arr1, arr2, 5)<<endl;
    return 0;
}