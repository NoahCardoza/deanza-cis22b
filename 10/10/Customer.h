/* *~*~*
  Specification file for the Customer class
  Written By: A. Student
  Changed by:
  IDE:
  *~**/
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

using std::string;

class Customer
{
private:
  int position;
  int years;
  int mileage;
  int serial;
  string name;

public:
  Customer()
  {
    this->position = 0;
    this->years = 0;
    this->mileage = 0;
    this->serial = 0;
    this->name = "";
  }

  // setters
  void setPosition(int position) { this->position = position; };
  void setYears(int years) { this->years = years; };
  void setMileage(int mileage) { this->mileage = mileage; };
  void setName(string name) { this->name = name; };

  // getters
  int getYears() { return years; };
  int getMileage() { return mileage; };
  string getName() { return name; };
  int getSerial()
  {
    int priority = mileage / 1000 + years - position;
    int serial = priority * 100 + (100 - position);

    return serial;
  };
};
#endif