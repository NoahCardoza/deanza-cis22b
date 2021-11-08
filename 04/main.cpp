// Lab: Queues 4
// Name:

#include <iostream>
#include <string>

#include "QueueADT.h"


using namespace std;

int main() {

    // Create the first queue (strings)
    Queue<string> s;

    string item;

    // Write a loop to enter an unknown number of names (assume one word strings).
    // The loop stops when you enter #.
    // As you are entering names, they are to be inserted into the first queue.
    while(item != "#")
    {
        cin >> item;

        if(item != "#")
        {
            s.push(item);
        }
    }


    // Create the second queue (doubles)
    Queue<double> d;
    double number;


    // Test the getLength function: - display the number of elements in the first queue
    // Test the getLength function: - display the number of elements in the second queue
    // (it should be 0!)

    if(s.isEmpty()) {
        cout << "Empty Queue!" << endl;
        return 0;
    }

    cout << s.getLength() << " " << d.getLength() << endl;


    // Write another loop to enter the number of units (double) into a parallel queue.

    for(int i = 0; i < s.getLength(); i++)
    {
        cin >> number;
        d.push(number);
    }

    // Display the two queues in parallel.
    string firstQueueFront = s.peek();

    double secondQueueRear = d.peekRear();



    while(!s.isEmpty())
    {
        cout << s.pop() << " " << d.pop() << endl;
    }

//
//    // Display the front element in the first queue
//    cout << firstQueueFront << endl;
//
//    // Display the rear element in the second queue
//    cout << secondQueueRear << endl;

    return 0;
}