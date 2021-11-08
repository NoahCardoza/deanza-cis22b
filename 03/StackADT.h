/*~*~*
CIS 22C
Project: Stack ADT

Written by: Noah Cardoza
IDE: CLion
*~*/

/*~*~*
   Stack template
*~*/

#ifndef STACK_ADT
#define STACK_ADT

template <class T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
    };

    StackNode *top;     // Pointer to the stack top
    int length;

    void _freeNode(StackNode *node);

public:
    Stack();
    ~Stack();

    bool push(T);
    T pop();
    T peek();
    bool isEmpty();
    int getLength();
};

#endif
