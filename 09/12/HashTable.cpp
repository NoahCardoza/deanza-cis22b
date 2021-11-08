// Implementation file for the Hash class
// Written By: A. Student
// Changed by: Noah Cardoza
// IDE: VS Code

#include <string>
#include <iostream>

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
  hash _set - abstract away the 3 statements always needed
              to insert a new node 
*~**/
void HashTable::_set(HashNode *bucket, Student *item)
{
    if (!bucket->isOccupied())
    {
        bucket->setOccupied(1);
        count++;
    }

    bucket->setItem(*item);
}

/*~*~*~*
  hash insert - linear probe
*~**/

bool HashTable::insert(Student &itemIn)
{
    HashNode *bucket;
    int key, stop;

    if (count == hashSize)
        return false;

    // stop when we loop back to the same key we started on
    key = stop = _hash(itemIn.getName());

    do
    {
        bucket = hashAry + key % hashSize;
        if (!bucket->isOccupied() || bucket->getItem().getName() == itemIn.getName())
        {
            _set(bucket, &itemIn);
            return true;
        }

    } while (stop != ++key % hashSize);

    return false;
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
bool HashTable::search(Student &itemOut, int &noCol, string searchKey)
{
    HashNode *bucket;
    Student item;
    int key, stop;

    // initalize to 0
    noCol = 0;

    // stop when we loop back to the same key we started on
    key = stop = _hash(searchKey);

    do
    {
        bucket = hashAry + key % hashSize;
        item = bucket->getItem();

        if (!bucket->isOccupied())
        {
            // since we haven't implemented a delete method
            // if a bucket isn't occupied then we
            // know it won't be anywhere after
            return false;
        }

        if (item.getName() == searchKey)
        {
            itemOut = item;
            return true;
        }

        noCol++;
    } while (stop != ++key % hashSize);

    return false;
}
