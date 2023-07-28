#include <iostream>
using namespace std;

// O(n ** 2)
template<size_t N>
void selectionSort(int (&arr)[N]) {
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {2, 1, 45, 0, 24, 54, 10};
    selectionSort(arr);
    for (int element : arr) {
        cout << element << endl;
    }
}