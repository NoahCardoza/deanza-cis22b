#include <iostream>
using namespace std;




class Stack_int
{
private:
   // Structure for the stack nodes
   struct StackNode {
       int value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

   void stack_free_node(StackNode *node) {
       if (node == NULL) return;
       cout << node->value << " - deleted!" << endl;
       stack_free_node(node->next);
       delete node;
   }

public:
   Stack_int(){ top = NULL; length = 0; }    //Constructor
   ~Stack_int();                            // Destructor

   // Stack operations
   bool isEmpty() { return length == 0; }
   bool push(int);
   // int pop();
   int peek() { return top->value; }
   int getLength() { return length; }
};

/**~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_int::push(int item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}

/**~*~*
   Destructor
*~**/
Stack_int::~Stack_int()
{
    stack_free_node(top);
    cout << "Empty stack!" << endl;
}


int main() {

    Stack_int s;
    int item;

    while (1) {
        cin >> item;
        if (item < 1) {
         break;
        }
        s.push(item);
    }

    return 0;
}