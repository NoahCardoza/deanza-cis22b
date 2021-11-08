// Specification file for the Student class
// Modified by: Noah Cardoza
// IDE: VS Code

#ifndef STUDENT_H
#define STUDENT_H

using std::string;

class Student
{
private:
    double gpa;
    string name;

public:
    Student()
    {
        name = "";
        gpa = -1;
    } // Constructor
    Student(string n, double g)
    {
        name = n;
        gpa = g;
    } // Overloaded Constructor

    // Setters and getters
    void setName(string n) { name = n; }
    void setGpa(double g) { gpa = g; }
    string getName() const { return name; }
    double getGpa() const { return gpa; }

    // Overloaded operators

    bool operator==(const Student &c) const
    {
        return name == c.name;
    }
};
#endif
