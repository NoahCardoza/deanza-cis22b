// Implementation file for the College class
// Written By: A. Student
// Changed By: Noah Cardoza
// IDE: Vs Code

#include <iostream>
#include <iomanip>
#include <string>

#include "College.h"

using namespace std;

//**************************************************
// Constructor
//**************************************************
College::College()
{
    rank = -1;
    code = "";
    name = "";
    cost = -1;
}

//**************************************************
// Overloaded Constructor
//**************************************************
College::College(int rk, string cd, string nm, int ct)
{
    rank = rk;
    code = cd;
    name = nm;
    cost = ct;
}

//***********************************************************
// Displays the values of the College object member variables
// on one line (horizontal display)
//***********************************************************

ostream &operator<<(ostream &output, const College &C)
{
    output << left;
    output << " " << setw(4) << C.code << "  ";
    output << " " << setw(2) << C.rank << "  ";
    output << " " << setw(27) << C.name << "  ";
    output << right;
    output << " " << setw(7) << C.cost << " ";
    output << left << endl;
    return output;
}

//***********************************************************
// Displays the values of the College object member variables
// one per line (vertical display)
//***********************************************************
void College::vDisplay() const
{
    cout << "              Rank: " << rank << endl;
    cout << "       School Name: " << name << endl;
    cout << "Cost of Attendance: $" << cost << endl;
}
