/**
 * Saving some typing
 * g++ -o labFortuneCookie.o labFortuneCookie.cpp -g
 * ./labFortuneCookie.o
 */
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    const char escape[2] = "n";
    srand(time(NULL));
    while (1)
    {
        cout << "Fortune Cookie" << endl;
        cout << "Open a fortune cookie" << endl;
        int randomNumber = rand() % 3;
        switch(randomNumber) {
            case 0:
                cout << "\"This is the first message!\"" << endl;
                break;
            case 1:
                cout << "\"This is the second message!\"" << endl;
                break;
            case 2:
                cout << "\"This is the third message!\"" << endl;
                break;
        }
        cout << "Crack open another one? (y/n)" << endl;
       char input;
        cin >> input;
        if (input == 'n') {
            return 0;
        }
    }
}