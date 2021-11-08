// Implementation file for the Hash class
// Written By: A. Student
// Changed by: Noah Carodza

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
    HashNode *bucket;
    int index, stop, noCol;

    // initalize to 0
    noCol = 0;

    if (count == hashSize)
        return false;

    // stop when we loop back to the same index we started on
    index = stop = _hash(itemIn.getName());

    do
    {
        bucket = hashAry + index % hashSize;
        if (!bucket->isOccupied())
        {
            bucket->setItem(itemIn);
            bucket->setTouched(true);
            bucket->setOccupied(1);
            bucket->setNoCollisions(noCol);
            count++;
            return true;
        }

        // reject duplicates
        if (bucket->getItem().getName() == itemIn.getName())
        {
            return false;
        }
        noCol++;
    } while (stop != ++index % hashSize);

    return false;
}

/*~*~*~*
   hash delete - linear probe
   - looks for key in hash table
   - if found:
       - copies its data to itemOut 
       - replaces data in the hash node with an "empty" record
       - returns true
   - if not found - returns false
*~**/

bool HashTable::remove(Student &itemOut, string key)
{
    HashNode *bucket;
    int index, stop;

    if (count == 0)
        return false;

    // stop when we loop back to the same index we started on
    index = stop = _hash(key);

    do
    {
        bucket = hashAry + index % hashSize;
        if (bucket->isUntouched())
        {
            // if this bucket has never bet set/unset there is
            // no way the value we are looking for could be past
            // this point
            return false;
        }

        // remove matching key from hashmap
        if (bucket->getItem().getName() == key)
        {
            Student empty;
            itemOut = bucket->getItem();
            bucket->setItem(empty);
            bucket->setOccupied(0);
            bucket->setNoCollisions(-1);
            count--;
            return true;
        }

    } while (stop != ++index % hashSize);

    return false;
}

/*~*~*~*
   hash search - linear probe
   if found: 
      - copy data to itemOut
      - returns the number of collisions for this key 
   if not found, returns -1
*~**/
int HashTable::search(Student &itemOut, string key)
{
    HashNode *bucket;
    Student item;
    int index, stop;

    if (count == 0)
        return false;

    // stop when we loop back to the same key we started on
    index = stop = _hash(key);

    do
    {
        bucket = hashAry + index % hashSize;
        item = bucket->getItem();

        if (bucket->isUntouched())
        {
            // since we haven't implemented a delete method
            // if a bucket isn't occupied then we
            // know it won't be anywhere after
            return -1;
        }

        if (bucket->isOccupied() && item.getName() == key)
        {
            itemOut = item;
            return bucket->getNoCollisions();
        }

    } while (stop != ++index % hashSize);

    return -1;
}
