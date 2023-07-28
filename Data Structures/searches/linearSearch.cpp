#include <iostream>
using namespace std;

int linearSearch(int valueToFind, int array[], uint low, uint high) {
    for (int i = low; i < high + 1; ++i) {
        if (array[i] == valueToFind) {
            return i;
        }
    }

    return -1;
}

int main() {

}