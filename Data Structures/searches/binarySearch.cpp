#include <iostream>
using namespace std;

int binarySearch(int randomNumber, int leftLimit = 0, int rightLimit = 1000) {
    // leftLimit: The smallest number in scope in which algorithm will work
    // rightLimit: The largest number in scope in which algorithm will work

    int middleNumber;
    int attemptsQuantity = 1;

    while (true) {
        middleNumber = (leftLimit + rightLimit) / 2;
        cout << attemptsQuantity << ") Make your guess: " << middleNumber << endl;

        if (middleNumber > randomNumber) {
            rightLimit = middleNumber;
        } else if (middleNumber < randomNumber) {
            leftLimit = middleNumber;
        } else {
            cout << "Success! Number was found in " << attemptsQuantity << " tries" << endl;
            break;
        }

        attemptsQuantity++;
    }

    return middleNumber;
}

int main() {
    int userNumber;
    cout << "Please type your number: ";
    cin >> userNumber;
    int result = binarySearch(userNumber);
}