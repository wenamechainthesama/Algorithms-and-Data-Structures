#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// O(n + k)
void countSort(int array[], int size) {
  int output[10];
  int count[10]{};
  int max = array[0];

  for (int i = 1; i < size; i++) {
    if (array[i] > max) max = array[i];
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

int main() {
    const uint size = 7;
    int arr[] = {2, 1, 5, 0, 4, 5, 1};
    countSort(arr, size);
    for (int element : arr) {
        cout << element << endl;
    }
}