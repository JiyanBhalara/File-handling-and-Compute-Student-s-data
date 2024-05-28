#ifndef JJB0363PROJECT3_HEADER_H
#define JJB0363PROJECT3_HEADER_H

// Include all necessary header files required for program.
#include <iostream>
#include <string.h>
#include <iomanip>
#include <ios>
#include <fstream>
#include <string>
// #include "getNumber.cpp"

using namespace std;


// Declaring global parameters/variables required for our program
const int NumOfTest = 5;
enum Menu
{
    Add = 1,
    Remove = 2,
    Display = 3,
    Search = 4,
    Results = 5,
    Quit = 6,
};

// Structure named Student as directed
struct Student
{
    string Name;
    int Id;
    int TestTaken;
    int *TestScore;
    double AvgTestScore;
};

// Declaring functions
int addStudent();
int removeStudent(int);
int search(int);
int display();
int exportResults();
int findMinimum(int [], int);

#endif


