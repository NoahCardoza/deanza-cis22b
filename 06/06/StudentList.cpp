// Implementation file for the Student List class
// Modified by: Noah Cardoza
// IDE: VS Code

#include <iostream> // For cout  and NULL
#include "StudentList.h"
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
StudentList::StudentList()
{
    head = new ListNode; // head points to the sentinel node

    head->stu.gpa = -1;
    head->stu.name = "";
    head->next = NULL;
    count = 0;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************

void StudentList::displayList() const
{
    ListNode *pCur; // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    cout << endl;
    while (pCur)
    {
        // Display the value in this node.
        cout << pCur->stu.gpa << " " << pCur->stu.name << endl;

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}

//**************************************************
// the first overloaded displayList: ...
//
//
//**************************************************

void StudentList::displayList(double gpa) const
{
    ListNode *pCur; // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    cout << endl;
    while (pCur)
    {
        // Display the value in this node if gpa matches the filter
        if (pCur->stu.gpa <= gpa)
        {
            cout << pCur->stu.gpa << " " << pCur->stu.name << endl;
        }

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}

//**************************************************
// the second overloaded displayList: ...
//
//
//**************************************************

void StudentList::displayList(double from, double to) const
{

    if (from > to)
    {
        swap(from, to);
    }

    ListNode *pCur; // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    cout << endl;
    while (pCur)
    {
        // Display the value in this node if gpa matches the filter
        if (from <= pCur->stu.gpa && pCur->stu.gpa <= to)
        {
            cout << pCur->stu.gpa << " " << pCur->stu.name << endl;
        }

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}

// The insertNode function inserts a node with
// stu copied to its value member.
//**************************************************
void StudentList::insertNode(Student dataIn)
{
    ListNode *newNode; // A new node
    ListNode *pCur;    // To traverse the list
    ListNode *pPre;    // The previous node

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->stu = dataIn;

    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find location: skip all nodes whose gpa is less than dataIn's gpa
    while (pCur != NULL && pCur->stu.name < dataIn.name)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;

    // Update the counter
    count++;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
StudentList::~StudentList()
{
}
