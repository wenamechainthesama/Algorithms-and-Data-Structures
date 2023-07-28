#include <iostream>
using namespace std;

int ternarySearch(int valueToFind, int array[], int left, int right) {
    /*
    Given array must be sorted
    */

    int m1 = left + (right - left) / 3;
    int m2 = right - (right - left) / 3;

    if (left >= right) return -1;

    if (array[m1] == valueToFind) return m1;
    if (array[m2] == valueToFind) return m2;
    
    if (array[m1] < valueToFind) {
        if (array[m2] < valueToFind) {
            left = m2;
        } else {
            left = m1;
            right = m2;
        }
    } else {
        right = m1;
    }

    return ternarySearch(valueToFind, array, left, right);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cout << ternarySearch(20, arr, 0, 9) << endl;
}