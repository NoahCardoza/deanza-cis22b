/*
 CIS 22C
 
 Sorted Circular Doubly-Linked List with Sentinel Node
 
 This program builds and displays a sorted list
 The list is sorted in ascending order by name
 
 Modified by: Noah Cardoza
 IDE: VS Code
 
 */
#include <iostream>
#include "StudentList.h"
using namespace std;

void buildList(StudentList &);

int main()
{
    // Define a StudentList object
    StudentList list;

    buildList(list); // insert data into the list

    string answer;
    cout << "Delete [Y/N]?";
    cin >> answer;
    if (answer == "Y" || answer == "y")
    {
        string targetName;
        cout << "Enter name to be removed from the list: " << endl;
        cin >> targetName;
        cout << targetName << (list.deleteNode(targetName) ? " - deleted!" : " - not found!") << endl;
    }
    cout << endl;
    list.displayListForw();
    list.displayListBack();
    return 0;
}

void buildList(StudentList &list)
{
    // Define and initialize an array of Student objects
    Student s[] =
        {{2.3, "Tom"}, {3.9, "Zoe"}, {2.5, "John"}, {3.1, "Linda"}, {3.5, "Aaron"}, {2.7, "Ann"}, {3.2, "Andy"}, {0, "#"}};

    //Insert data from array into the linked list
    for (int i = 0; s[i].name != "#"; i++)
    {
        list.insertNode(s[i]);
    }
}
