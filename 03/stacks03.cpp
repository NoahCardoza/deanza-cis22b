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

public:
    Stack_int(){ top = NULL; length = 0; }    //Constructor
    ~Stack_int();                            // Destructor

    // Stack operations
    bool isEmpty() { return length == 0; }
    bool push(int);
    int pop();
    int peek();
    int getLength();
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
  Member function pop pops the value at the top
  of the stack off, and returns it
  Assume stack is not empty
*~**/
int Stack_int::pop() {
    StackNode *newTop = top->next;
    int value = top->value;
    delete top;
    top = newTop;
    length--;
    return value;
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

    if (s.isEmpty()) {
        cout << "Empty Stack!" << endl;
    }

    while (!s.isEmpty()) {
        cout << s.pop() << endl;
    }

    return 0;
}
