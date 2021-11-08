// Specification file for the Student class
// Modified by: Noah Cardoza
// IDE: VS Code

#ifndef STUDENT_H
#define STUDENT_H

using std::string;

class Student {
private:
    double gpa;
    string name;

    
public:
    Student(void) {
        this->gpa = -1;
        this->name = "";
    }

    Student(double gpa, string name) {
        this->gpa = gpa;
        this->name = name;
    }
    
    double getGpa() {
        return gpa;
    }

    string getName() {
        return name;
    }
};
#endif
