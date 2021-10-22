#include "BinarySearchTree.h"  // BST ADT
#include "College.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

/* Write your code here */

void hDisplay(College &);
void vDisplay(College &);
void iDisplay(College &, int);

int main()
{
    string filename;
    BinarySearchTree<College> bst;

    cout << "What is the input file's name? ";
    cin >> filename;
     /* Write your code here: build the BST from an input file  */
     
    char option;
    cout << "Display Inorder [Y/N]? ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        cout << endl << "Inorder: " << endl;
        /* Write your code here: use hDisplay */
        
        cout << endl;
    }
    cout << "Display Indented List [Y/N]? ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        cout << "Indented List: " << endl;
        /* Write your code here: use iDisplay */
        cout << endl;
    }
    cout << "Display Leaf Nodes [Y/N]? ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        cout  << "Leaf Nodes: " << endl;
        /* Write your code here: use hDisplay */
        cout << endl;
    }

   /* Write your code here: test driver for search (See previous homeowrk assignments  */
   
    return 0;
}

/* Write your code here */


/*
 horizontal display: all items on one line
*/
void hDisplay (College &item)
{
    cout << left;
    cout << " " << setw(4) << item.getCode() << "  ";
    cout << " " << setw(2) << item.getRank() << "  ";
    cout << " " << setw(27)<< item.getName() << "  ";
    cout << right;
    cout << " " << setw(7) << item.getCost() << " ";
    cout << left << endl;
}

/*
 vertical display: one item per line
*/
void vDisplay (College &item)
{
    cout << "              Rank: " << item.getRank() << endl;
    cout << "       School Name: " << item.getName() << endl;
    cout << "Cost of Attendance: $" << item.getCost() << endl;
}

/*
 indented tree display: one item per line, including the level number
*/
void iDisplay(College &item, int level)
{
    for (int i = 1; i < level; i++)
        cout << "..";
    cout << level << "). " << item.getCode() << endl;
}

