#include <iostream>
using namespace std;

// O(n ** 2)
void bubbleSort(int *arr, int arraySize) {
    if (arraySize == 0 || arraySize == 1) {
        return;
    }

    int maxIndex = 0;

    while (arraySize != 0) {
        for (int i = 0; i < arraySize; ++i) {
            if (arr[i]< arr[i-1]) {
                int tempElement = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tempElement;
            }

            maxIndex = i;
        }

        arraySize = maxIndex;
    }
}

int main() {
    int arr[] = {3, 9, 6, 1, 0, 7, 20, 84, 2, 74};
    bubbleSort(arr, 10);
    for (int element : arr) {
        cout << element << endl;
    }

    /*
    Output:
    0
    1
    2
    3
    6
    7
    9
    20
    74
    84
    */
}