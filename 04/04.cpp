// Lab: Queues 4
// Name: Noah Cardoza

#include <iostream>
#include <string>

#include "QueueADT.h"

using namespace std;

int main() {
    Queue<string> students;
    Queue<double> grades;

    string student;
    double grade;
    int i;

    // read until "#"
    while (1) {
        cin >> student;
        if (student == "#") {
            break;
        }
        students.push(student);
    }

    i = students.getLength();

    if (!i) { // no student names were inputted
        cout << "Empty Queue!" << endl;
        return 0;
    }

    cout << i << ' ' << grades.getLength() << endl;

    // read in the matching grades for the students
    while (i--) {
        cin >> grade;
        grades.push(grade);
    }

    // save the front an rear values since after the
    // next loop the queue's will be empty
    student = students.peek();
    grade = grades.peekRear();

    // display the student's and their grading information
    while (!students.isEmpty()) {
        cout << students.pop() << ' ' << grades.pop() << endl;
    }

    // output what used to be the front of student
    // and the rear of grade
    cout << student << endl << endl << grade << endl;
    cout << grade << endl;

     return 0;
}