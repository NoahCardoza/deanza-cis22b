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

void printHeader();
void printFooter();
void printCustomer(Customer *c);
void load(string filename, Heap<Customer> *heap);
int cmp(Customer *c, Customer *k);

int main()
{
   Heap<Customer> heap;
   string filename;
   cout << "Input file name: ";
   getline(cin, filename);

   load(filename, &heap);

   return 0;
}

void load(string filename, Heap<Customer> *heap)
{
   char op;
   int years, mileage;
   string name;

   int position = 0; // to track the order Customers are inserted
   int served = 0;
   int rejected = 0;

   Customer *c;

   ifstream fin(filename);
   if (!fin)
   {
      cout << "Error opening the input file: \"" << filename << "\"" << endl;
      exit(EXIT_FAILURE);
   }

   printHeader();

   while (fin.good())
   {
      fin >>
          op;
      if (op == 'A')
      {
         c = new Customer;
         // read information into memory
         fin >> years;
         fin >> mileage;
         getline(fin, name);

         // set Customer object
         c->setPosition(position++);
         c->setYears(years);
         c->setMileage(mileage);
         c->setName(name);

         heap->insertHeap(*c, cmp);
      }
      else if (op == 'S')
      {
         heap->deleteHeap(c, cmp);
         printCustomer(c);
         served++;
      }
      else
      {
         cout << "Error: Unkowner operation \"" << op << "\"" << endl;
         fin.close();
         exit(1);
      }
   }

   fin.close();

   printFooter();
   cout << "Served overbooked customers: " << served << endl
        << endl;

   printHeader();

   while (!heap->isEmpty())
   {
      heap->deleteHeap(c, cmp);
      printCustomer(c);
      rejected++;
   }

   printFooter();

   cout << "Rejected overbooked customers: " << rejected << endl;
}

int cmp(Customer *parent, Customer *child)
{
   if (parent->getSerial() > child->getSerial())
      return -1;
   if (parent->getSerial() == child->getSerial())
      return 0;
   return 1;
}

void printHeader()
{
   cout << " ==== =======   =============" << endl
        << " Year Mileage   Name" << endl
        << " ==== =======   =============" << endl;
}

void printFooter()
{
   cout << " ==== =======   =============" << endl;
}

void printCustomer(Customer *c)
{
   cout << right;
   cout << " " << setw(3) << c->getYears() << " ";
   cout << left;
   cout << " " << setw(5) << c->getMileage() << "   ";
   cout << " " << c->getName() << endl;
}