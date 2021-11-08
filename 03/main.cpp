/*~*~*
CIS 22C
Project: Stack ADT

Written by:
IDE:
*~*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "../StackADT.h"

void printInfo();

int main()
{
    string filenames[] = {"numbers1.txt", "numbers2.txt", "numbers3.txt", ""};
    
    printInfo();
    for (int i = 0; filenames[i] != ""; i++)
    {
           // call a function to process the input file using a stack
    }
    
    return 0;
}

/*~*~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << "Project: Stack ADT" << endl;
}

/*~*~*~*~*~*~ Save the output below



*~*/