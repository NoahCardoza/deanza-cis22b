// Specification file for the HashNode class
// Written By: A. Student
// Modified by: Noah Cardoza
// IDE: VS Code

#ifndef _HASH_NODE
#define _HASH_NODE

template <class T>
class HashNode
{
private:
    T item;
    int occupied;
    int noCollisions;
    bool touched;

public:
    // constructors
    HashNode()
    {
        touched = false;
        occupied = 0;
        noCollisions = 0;
    }
    HashNode(T item)
    {
        touched = true;
        this->item = item;
        occupied = 1;
        noCollisions = 0;
    }
    HashNode(T item, int ocp, int nCol)
    {
        touched = true;
        this->item = item;
        occupied = ocp;
        noCollisions = nCol;
    }
    // setters
    void setItem(const T &item) { this->item = item; }
    void setTouched(bool value) { touched = value; }
    void setOccupied(int ocp) { occupied = ocp; }
    void setNoCollisions(int nCol) { noCollisions = nCol; }

    // getters
    T getItem() const { return item; }
    bool isOccupied() const { return occupied == 1; }
    bool isUntouched() const { return touched == false; }
    int getOccupied() const { return occupied; }
    int getNoCollisions() const { return noCollisions; }
};

#endif
