#include <iostream>
using namespace std;

// O(n / m + m - 1)
int jumpSearch(int valueToFind, int array[], int low, int high, int step) {
    /*
    Given array must be sorted
    */

    if (array[low] == valueToFind) return low;
    if (array[high] == valueToFind) return high;

    if (low < valueToFind < high) {
        // Linear Search
        for (int i = high; i > low; --i) {
            if (array[i] == valueToFind) return i;
        }
        return -1;
    }

    low += step;
    high += step;
    
    return jumpSearch(valueToFind, array, low, high, step);
}    

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cout << jumpSearch(10, arr, 0, 9, 3) << endl;
}