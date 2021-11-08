#include <iostream>
#include <string>
using namespace std;

class Queue_str
{
private:
   // Structure for the stack nodes
   struct QueueNode {
       string value;        // Value in the node
       QueueNode *next;     // Pointer to next node
   };

   QueueNode *front;          // Pointer to the first node
   QueueNode *rear;           // Pointer to the last node
   int length;                // Number of nodes in the queue

public:
   Queue_str(){ front = rear = NULL; length = 0; }

    Queue_str(QueueNode *front);

    //Constructor
   ~Queue_str();                                    // Destructor

   // Queue operations
   bool isEmpty() { return length == 0; }
   bool push(string);
   string pop();
   string peek() { return front->value; }
   string peekRear() { return rear->value; }
   int getLength() { return length; }
};

/**~*~*
   Destructor
*~**/
Queue_str::~Queue_str()
{
    QueueNode *next;

    while (length--) {
        next = front->next;
        delete front;
        front = next;
    }

    rear = NULL;
}

/**~*~*
  Member function push: inserts the argument into the queue
*~**/
bool  Queue_str::push(string value)
{
   QueueNode *node; // Pointer to a new node

   // Allocate a new node and store num there.
    node = new QueueNode;

    if (!node) {
       return false;
   }

   node->value = value;
   node->next = NULL;

   if (!front) { // front is NULL: empty queue
       front = node;
   } else {
       rear->next = node;
   }

   rear = node;
   length++;

   return true;
}

/**~*~*
  Member function dequeue deletes the value at the front
  of the queue and returns it.
  Assume queue has at least one node
*~**/
string Queue_str::pop()
{
    string value;
    QueueNode *next;

    value = front->value;
    next = front->next;

    delete front;
    front = next;

    if (!front) { // NULL out the rear if we popped the last element
        rear = NULL;
    }

    length--;

    return value;
}


int main() {

     Queue_str q;
     string item;

    // read until "#"
    while (1) {
        cin >> item;
        if (item == "#") {
            break;
        }
        q.push(item);
    }

    if (q.isEmpty()) {
        cout << "Empty Queue!" << endl;
    }

    while (!q.isEmpty()) {
        cout << q.pop() << endl;
    }

     return 0;
}