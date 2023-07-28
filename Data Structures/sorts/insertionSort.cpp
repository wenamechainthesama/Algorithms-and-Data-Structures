#include <iostream>
using namespace std;

// O(n ** 2)
template<size_t N>
void insertionSort(int (&arr)[N]) {
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < length; ++i) {
        int sortedRange = i - 1;
        while (sortedRange > -1 && arr[sortedRange] > arr[sortedRange + 1]) {
            int temp = arr[sortedRange];
            arr[sortedRange] = arr[sortedRange+1];
            arr[sortedRange+1] = temp;
            sortedRange--;
        }
    }
}

int main() {
    int arr[] = {2, 1, 45, 0, 24, 54, 10};
    insertionSort(arr);
    for (int element : arr) {
        cout << element << endl;
    }
}