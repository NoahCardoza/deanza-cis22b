// Implementation file for the Hash class
// Written By: A. Student
// Changed by: Noah Cardoza
// IDE: VS Code

#include <string>

#include "HashTable.h"

using namespace std;

/*~*~*~*
  A simple hash function 
 *~**/
int HashTable::_hash(string key) const
{
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % hashSize;
};

/*~*~*~*
  hash insert - linear probe
*~**/

bool HashTable::insert(Student &itemIn)
{
    if (count == hashSize)
        return false;
    /* write your code here */

    return true;
}

/*~*~*~*
   hash delete - linear probe
*~**/

bool HashTable::remove(Student &itemOut)
{
    return false;
}

/*~*~*~*
   hash search - linear probe
   if found: 
      - copy data to itemOut
      - copy number of collisions for this key tp noCol
      - returns true
   if not found, returns false
*~**/
bool HashTable::search(Student &itemOut, int &noCol, string key)
{
    /* write your code here */

    return false;
}
