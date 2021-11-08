// Implementation file for the College class
// Written By: A. Student
// Changed By: Noah Cardoza
// IDE: VS Code

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
// void College::hDdisplay() const
// {

// }

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

// overloaded operators

ostream &operator<<(ostream &output, const College &c)
{
    output << left;
    output << " " << setw(4) << c.code << "  ";
    output << " " << setw(2) << c.rank << "  ";
    output << " " << setw(27) << c.name << "  ";
    output << right;
    output << " " << setw(7) << c.cost << " ";
    return output;
}

bool College::operator<(const College &c) const
{
    return code < c.code;
}
bool College::operator>(const College &c) const
{
    return code > c.code;
}
bool College::operator==(const College &c) const
{
    return code == c.code;
}

/* Write your code here to define the following oveloaded operator:
    - the stream insertion operator ( << )
 */
