/* COMP2011 Spring 2019
 * Assignment 2
 * File: pa2.cpp
 * Function definitions
 *
 * Student name: (FILL YOUR NAME HERE)
 * Student ID: (FILL YOUR STUDENT ID NUMBER HERE)
 * Student email: (FILL YOUR EMAIL HERE)
 * Student lab section: (FILL YOUR LAB SECTION HERE)
 */

#include <iostream>
#include "func.h"
using namespace std;

// This function is used for printing out the Canvas
void printCanvas(char canvas[MAX_ROW][MAX_COL])
{
    cout << "The current canvas: " << endl;
    cout << "   ";
    for (int i = 0; i < MAX_COL; i++)
        cout << i % 10;
    cout << endl;
    cout << " //";
    for (int i = 0; i < MAX_COL; i++)
        cout << "=";
    cout << "\\\\" << endl;
    for (int i = 0; i < MAX_ROW; i++)
    {
        cout << i % 10 << "||";
        for (int j = 0; j < MAX_COL; j++)
        {
            if (canvas[i][j] == NULL_CHAR)
                cout << ' ';
            else
                cout << canvas[i][j];
        }
        cout << "||" << endl;
    }
    cout << " \\\\";
    for (int i = 0; i < MAX_COL; i++)
        cout << "=";
    cout << "//" << endl;
}

// TODO: Please implemement the required recursive functions stated in the header file (func.h) below.
int lineInvalid(char canvas[MAX_ROW][MAX_COL], int row, int col, int length) 
{
    return (length == 0 || row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL);
}

int pointOutOfRange(int row, int col) 
{
    return (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL);
}

int makeHorizontalLine(char canvas[MAX_ROW][MAX_COL], int row, int col, int length)
{
    if (lineInvalid(canvas, row, col, length))
        return 0;                   //end of line
    if (canvas[row][col] == '|') 
        canvas[row][col] = '+';     //handle '|'
    else 
        canvas[row][col] = '-';     //handle everthing else
    return 1 + makeHorizontalLine(canvas, row, col + 1, length - 1);
}

int makeVerticalLine(char canvas[MAX_ROW][MAX_COL], int row, int col, int length) 
{
    if (lineInvalid(canvas, row, col, length))
        return 0;                   //end of line
    if (canvas[row][col] == '-')
        canvas[row][col] = '+';     //handle '-'
    else
        canvas[row][col] = '|';     //handle everthing else
    return 1 + makeVerticalLine(canvas, row + 1, col, length - 1);
}

int makeUpwardSlantingLine(char canvas[MAX_ROW][MAX_COL], int row, int col, int length)
{
    if (lineInvalid(canvas, row, col, length))
        return 0;                   //end of line
    if (canvas[row][col] == '\\')
        canvas[row][col] = 'X';     //handle '\'
    else
        canvas[row][col] = '/';     //handle everthing else
    return 1 + makeUpwardSlantingLine(canvas, row - 1, col + 1, length - 1);
}

int makeDownwardSlantingLine(char canvas[MAX_ROW][MAX_COL], int row, int col, int length)
{
    if (lineInvalid(canvas, row, col, length))
        return 0;                   //end of line
    if (canvas[row][col] == '/')
        canvas[row][col] = 'X';     //handle '/'
    else
        canvas[row][col] = '\\';    //handle everthing else
    return 1 + makeDownwardSlantingLine(canvas, row + 1, col + 1, length - 1);
}

// Recursive functions for making patterns
void makeHive(char canvas[MAX_ROW][MAX_COL], int row, int col, int depth) 
{
    if (!pointOutOfRange(row, col) && depth > 0)
    {
        canvas[row][col] = '_';
        if (!pointOutOfRange(row, col + 1))
            canvas[row][col + 1] = '/';
        if (!pointOutOfRange(row + 1, col + 1))
            canvas[row + 1][col + 1] = '\\';
        makeHive(canvas, row - 1, col + 2, depth - 1);
        makeHive(canvas, row + 1, col + 2, depth - 1);
        makeHive(canvas, row - 1, col - 2, depth - 1);
        makeHive(canvas, row + 1, col - 2, depth - 1);
    }
}

void makeTriangle(char canvas[MAX_ROW][MAX_COL], int row, int col, int layer)
{
    if (!pointOutOfRange(row, col))
    {
        if (layer > 0)
        {
            if (!pointOutOfRange(row, col - layer))
                canvas[row][col - layer] = '/';
            if (!pointOutOfRange(row, col + 3))
                canvas[row][col + layer] = '\\';
            for (int i = col + layer - 1; i > col - layer; i--)
            {
                if (!pointOutOfRange(row, i))
                    canvas[row][i] = '-';
            }
        }
        else
        {
            if (!pointOutOfRange(row, col))
                canvas[row][col] = '.';
            return;
        }
    } else {
        return;
    }
    makeTriangle(canvas, row - 1, col, layer - 1);
}

// Recursive function for filling an area
int fill(char canvas[MAX_ROW][MAX_COL], int row, int col, char fillChar)
{
    if (!canvas[row][col] && !pointOutOfRange(row, col))
    {
        int pointsFilled = 1;
        canvas[row][col] = fillChar;
        pointsFilled += fill(canvas, row + 1, col, fillChar);
        pointsFilled += fill(canvas, row - 1, col, fillChar);
        pointsFilled += fill(canvas, row, col + 1, fillChar);
        pointsFilled += fill(canvas, row, col - 1, fillChar);
        return pointsFilled;
    }
    else
    {
        return 0;
    }
}

// Recursive function To repeat the pattern of a kind
void repeatPattern(char canvas[MAX_ROW][MAX_COL], int row, int col, int interval_row, int interval_col, Shape choice,
                   int patternParameter, int times)
{
    if (times > 0)
    {
        switch(choice) 
        {
            case TRIANGLE:
                makeTriangle(canvas, row, col, patternParameter);
                break;
            case HIVE:
                makeHive(canvas, row, col, patternParameter);
                break;
            case VERTICAL:
                makeVerticalLine(canvas, row, col, patternParameter);
                break;
            case HORIZONTAL:
                makeHorizontalLine(canvas, row, col, patternParameter);
                break;
            case UPWARD_SLANTING_LINE:
                makeUpwardSlantingLine(canvas, row, col, patternParameter);
                break;
            case DOWNWARD_SLANTING_LINE:
                makeDownwardSlantingLine(canvas, row, col, patternParameter);
                break;
            default:
                break;
        }
        repeatPattern(canvas, row + interval_row, col - interval_col, interval_row, interval_col, choice, patternParameter, times - 1);
        repeatPattern(canvas, row - interval_row, col + interval_col, interval_row, interval_col, choice, patternParameter, times - 1);
        repeatPattern(canvas, row + interval_row, col + interval_col, interval_row, interval_col, choice, patternParameter, times - 1);
        repeatPattern(canvas, row - interval_row, col - interval_col, interval_row, interval_col, choice, patternParameter, times - 1);
    } else {
        return;
    }
}
