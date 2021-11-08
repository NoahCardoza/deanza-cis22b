/*
  Heaps - ADT

  This program will read data about overbooked customers,
  find their priority and serial numbers, build a heap, then display
  customers in priority sequence
 
  Written By: A. Student
  Changed By:
  IDE:
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include "Customer.h"
#include "Heap.h"

using namespace std;

/* Write your code here */

int main()
{
   string inputFileName;
   cout << "Input file name: ";
   getline(cin, inputFileName);

   ifstream inFile(inputFileName);
   if (!inFile)
   {
      cout << "Error opening the input file: \"" << inputFileName << "\"" << endl;
      exit(EXIT_FAILURE);
   }

   /* Write your code here */

   inFile.close();

   /* Write your code here */

   return 0;
}

/* Write your code here */
