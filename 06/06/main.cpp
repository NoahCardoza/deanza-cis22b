/*
 CIS 22C
 
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

    list.displayList();
    double gpa;
    cout << "Enter a gpa: ";
    cin >> gpa;
    list.displayList(gpa);
    double from, to;
    cout << "Enter a gpa range: ";
    cin >> from >> to;
    list.displayList(from, to);

    return 0;
}

void buildList(StudentList &list)
{
    // Define and initialize an array of Student objects
    Student s[10] =
        {{2.3, "Tom"}, {2.5, "John"}, {3.1, "Paul"}, {3.9, "Linda"}, {3.6, "Bob"}, {2.7, "Ann"}, {4.0, "Mary"}, {3.2, "Andy"}, {0, "#"}};

    //Insert data from array into the linked list
    for (int i = 0; s[i].name != "#"; i++)
    {
        list.insertNode(s[i]);
    }
}
