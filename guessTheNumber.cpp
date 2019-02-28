/**
 * Saving some typing
 * g++ -o guessTheNumber.o guessTheNumber.cpp -g
 * ./guessTheNumber.o
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char **argv)
{
    int randomNumber = rand() % 100 + 1;
    cout << randomNumber << endl;
    int guessNumber = 0;
    bool correct = false;
    while (!correct) {
        cout << "Enter a number to guess : ";
        cin >> guessNumber;
        if (guessNumber == randomNumber) {
            cout << "u win !" << endl;
            correct = true;
        } else if (guessNumber > randomNumber) {
            cout << "too big" << endl;
        } else {
            cout << "too small" << endl;
        }
    }
    return 0;
}
