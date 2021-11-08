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
   Queue_str(){ front = rear = NULL; length = 0; }    //Constructor
   //~Queue_str();                                    // Destructor

   // Queue operations
   bool isEmpty() { return length == 0; }
   bool push(string);
   // string pop();
   string peek() { return front->value; }
   string peekRear() { return rear->value; }
   int getLength() { return length; }
};

/**~*~*
  Member function push: inserts the argument into the queue
*~**/
bool  Queue_str::push(string item)
{
   QueueNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new QueueNode;
   if (!newNode)
       return false;
   newNode->value = item;
   newNode->next = NULL;

   // Update links and counter
   if (!front) // front is NULL: empty queue
       front = newNode;
   else
       rear->next = newNode;

   rear = newNode;
   length++;

   return true;
}



int main() {

     Queue_str q;
     string item;

    while (1) {
        cin >> item;
        if (item == "#") {
            break;
        }
        q.push(item);
    }

    cout << q.getLength() << endl;
    if (q.isEmpty()) {
        cout << "Empty Queue!" << endl;
    } else {
        cout << q.peek() << endl;
        cout << q.peekRear() << endl;
    }

     return 0;
}