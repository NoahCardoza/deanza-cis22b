// Specification file for the ListNode class
// Changed By: Noah Cardoza
// IDE: VS Code

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include "College.h"

class ListNode
{
private:
    College data;   // store data
    ListNode *forw; // a pointer to the next node in the list
    ListNode *back; // a pointer to the previous node in the list
public:
    //Constructor
    ListNode() { forw = back = NULL; }
    ListNode(const College &dataIn, ListNode *forw = NULL, ListNode *back = NULL) { data = dataIn; }

    // setters
    // set the forw pointer
    void setNext(ListNode *nextPtr) { forw = nextPtr; }
    // set the back pointer
    void setPrev(ListNode *prevPtr) { back = prevPtr; }

    // getters
    // return pointer in the next node
    ListNode *getNext() const { return forw; }
    // return pointer in the previous node
    ListNode *getPrev() const { return back; }

    // return data object in the listnode: getData()
    College getData() const { return data; }
};

#endif
