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
    cout << "Insert [Y/N]?";
    cin >> answer;
    if (answer == "Y" || answer == "y")
    {
        Student s;
        cout << "Enter gpa then enter name: " << endl;
        cin >> s.gpa >> s.name;
        if (!list.insertNode(s))
        {
            cout << s.name << " - rejected: duplicate key!" << endl;
        }
    }
    cout << endl;
    list.displayListForw();
    list.displayListBack();
    return 0;
}

void buildList(StudentList &list)
{
    // Define and initialize an array of Student objects
    Student s[10] =
        {{2.3, "Tom"}, {2.5, "John"}, {3.1, "Linda"}, {2.7, "Ann"}, {3.2, "Andy"}, {0, "#"}};

    //Insert data from array into the linked list
    for (int i = 0; s[i].name != "#"; i++)
    {
        list.insertNode(s[i]);
    }
}
