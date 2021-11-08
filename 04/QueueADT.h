// Lab: Queues 4
// Name: Noah Cardoza

#ifndef WK01_QUEUEADT_H
#define WK01_QUEUEADT_H

template<class T>
class Queue
{
private:
    // Structure for the stack nodes
    struct QueueNode {
        T value;        // Value in the node
        QueueNode *next;     // Pointer to next node
        QueueNode *prev;     // Pointer to prev node
    };

    QueueNode *front;          // Pointer to the first node
    QueueNode *rear;           // Pointer to the last node
    int length;                // Number of nodes in the queue

public:
    Queue(){ front = rear = NULL; length = 0; }

    Queue(QueueNode *front);
    ~Queue();

    // Queue operations
    bool isEmpty() { return length == 0; }
    bool push(T);
    T pop();
    T peek() { return front->value; }
    T peekRear() { return rear->value; }
    int getLength() { return length; }
};

/**~*~*
   Destructor: free all all the memory in the linked list
*~**/
template <class T>
Queue<T>::~Queue()
{
    QueueNode *next;

    while (length--) {
        next = front->next;
        delete front;
        front = next;
    }

    front = NULL;
    rear = NULL;
}

/**~*~*
  Member function push: inserts the argument into the queue
*~**/
template <class T>
bool  Queue<T>::push(T value)
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
        node->prev = NULL;
    } else {
        rear->next = node;
        node->prev = rear;
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
template <class T>
T Queue<T>::pop()
{
    T value;
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

#endif //WK01_QUEUEADT_H
