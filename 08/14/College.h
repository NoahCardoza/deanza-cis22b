// Specification file for the College class
// Written By: A. Student
// Changed By:
// IDE: Xcode

#ifndef COLLEGE_H
#define COLLEGE_H

#include <string>

using std::ostream;
using std::string;

class College; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator<<(ostream &, const College &);

class College
{
private:
    /* Write your code here */

public:
    //constructors
    /* Write your code here */

    //setters
    /* Write your code here */

    //getters
    /* Write your code here */

    //other functions if any
    /* Write your code here */

    // overloaded operators
    /* Write your code here */

    // Friends
    friend ostream &operator<<(ostream &, const College &);
};

#endif
