/*
 * COMP2011 (Spring 2019) Assignment 1: The hailstone sequence
 *
 * Student name: Wong Tat Hang (Alex)
 * Student ID: 20511603
 * Student email: thwongaz@connect.ust.hk
 * Student lab section: LA1
 */

/**
 * Compliling and running the program
 * g++ -o hailstone.o hailstone.cpp -g
 * ./hailstone.o
 */

#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std;

#define NUMBERS_IN_A_ROW        8

typedef vector<int> int_v;

void hailstoneGenerator(int_v *seq, int num)
{
    seq->push_back(num);
    if (seq->back() == 3)                       //end of sequence, exit                     
        return;
    hailstoneGenerator(seq, seq->back() % 2 == 0 ? seq->back() / 2 : seq->back() * 3 + 3); //recure
}

/*
 * printHailstoneSequence(n) prints the hailstone sequence for n.
 */
void printHailstoneSequence(int n)
{
    int_v hailstoneSeq;
    hailstoneGenerator(&hailstoneSeq, n);
    for (auto i = hailstoneSeq.begin(); i != hailstoneSeq.end(); i++) 
    {
        cout << *i << '\t';
        if (distance(hailstoneSeq.begin(), i) % NUMBERS_IN_A_ROW == (NUMBERS_IN_A_ROW - 1))
            cout << '\n';
    }
    cout << '\n';
}

/*
 * shortestHailstoneSequenceLength(start, end) returns the length of the shortest hailstone sequence in the range [start, end].
 */
int shortestHailstoneSequenceLength(int start, int end)
{
    int shortestLength = numeric_limits<int>::max();
    for (int i = start; i < end + 1; i++)
    {
        int_v hailstoneSeq;
        hailstoneGenerator(&hailstoneSeq, i);
        if (hailstoneSeq.size() < shortestLength)
            shortestLength = hailstoneSeq.size();
    }
    return shortestLength;
}

/*
 * printHistogram(start, end) prints the histogram of the distribution of hailstone sequence lengths for the sequences in [start, end].
 */
void printHistogram(int start, int end)
{
    string grpString[5];
    for (int i = start; i < end + 1; i++)
    {
        int_v hailstoneSeq;
        hailstoneGenerator(&hailstoneSeq, i);
        grpString[hailstoneSeq.size() > 40 ? 4 : (hailstoneSeq.size() - 1) / 10].push_back('*');
    }
    for (int i = 0; i < 5; i++)
    {
        if (grpString[i].empty())
            grpString[i].push_back('0');
        cout << grpString[i] << '\n';
    }
}

/*
 * main() is the entry point of the program.
 * Do NOT modify it in any way.
 */
int main()
{
    //Define the variable for getting the user's choice.
    int choice;

    //Print the menu.
    cout << "Assignment 1: The hailstone sequence" << endl;
    cout << "1. Print a hailstone sequence" << endl;
    cout << "2. Find the shortest hailstone sequence length" << endl;
    cout << "3. Print a hailstone histogram" << endl;
    cout << endl;
    cout << "Enter your choice: ";

    //Get the choice.
    cin >> choice;

    //Perform a basic input validation.
    while (choice < 1 || choice > 3)
    {
        cout << "Please enter a valid choice: ";
        cin >> choice;
    }

    cout << endl;

    if (choice == 1) //Print a hailstone sequence.
    {
        //Get n.
        int n;
        cout << "Enter an integer n: ";
        cin >> n;

        //Perform a basic input validation.
        while (n < 1 || n > 10000)
        {
            cout << "Please enter a valid n: ";
            cin >> n;
        }

        //Output the result.
        cout << endl;
        cout << "The hailstone sequence for " << n << " is:" << endl;
        printHailstoneSequence(n);
    }
    else if (choice == 2) //Find the shortest hailstone sequence.
    {
        //Get start and end.
        int start, end;
        cout << "Enter the start and the end of the range: ";
        cin >> start >> end;

        //Perform a basic input validation.
        while (start > end || start < 1 || end < 1 || start > 10000 || end > 10000)
        {
            cout << "Please enter a valid range: ";
            cin >> start >> end;
        }

        //Output the result.
        cout << endl;
        cout << "The shortest hailstone sequence within the range [" << start << ", " << end << "] has a length of " << shortestHailstoneSequenceLength(start, end) << "." << endl;
    }
    else if (choice == 3) // Print a hailstone histogram.
    {
        //Get start and end.
        int start, end;
        cout << "Enter the start and the end of the range: ";
        cin >> start >> end;

        //Perform a basic input validation.
        while (start > end || end - start >= 100 || start < 1 || end < 1 || start > 10000 || end > 10000)
        {
            cout << "Please enter a valid range: ";
            cin >> start >> end;
        }

        //Output the result.
        cout << endl;
        cout << "The histogram of the hailstone sequence length distribution:" << endl;
        printHistogram(start, end);
    }

    //Exit the program.
    return 0;
}