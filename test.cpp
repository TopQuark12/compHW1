/**
 * Saving some typing
 * g++ -o test.o test.cpp -g
 * ./test.o
 */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int a = 10;

enum shapes
{
    text,
    circle,
    rectangle,
    line
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    printf("Hello World \n");
    //int a = 10;
    int b = 3;
    char testString[30];
    float ans = static_cast<double>(a) / b;
    cout << text << endl;
    scanf("%s",testString);
    printf("%s\n",testString);
    printf("%i\n",b);
    puts("end"); //puts prints the string with \n appended
    //cin >> b;
    return 0;
}