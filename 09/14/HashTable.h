// Specification file for the Hash class
// Written By: A. Student
// Modified by: Noah Cardoza
// IDE: VS Code

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashNode.h"

template <class T>
class HashTable
{
private:
    HashNode<T> *hashAry;
    int hashSize;
    int count;

public:
    HashTable()
    {
        count = 0;
        hashSize = 53;
        hashAry = new HashNode<T>[hashSize];
    }
    HashTable(int n)
    {
        count = 0;
        hashSize = n;
        hashAry = new HashNode<T>[hashSize];
    }
    ~HashTable() { delete[] hashAry; }

    int getCount() const { return count; }
    int getSize() const { return hashSize; }
    double getLoadFactor() const { return 100.0 * count / hashSize; }
    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == hashSize; }

    bool insert(const T &itemIn, int h(const T &key, int size));
    bool remove(T &itemOut, const T &key, int h(const T &key, int size));
    int search(T &itemOut, const T &key, int h(const T &key, int size));
};

/*~*~*~*
   Insert an item into the hash table
   It does not reject duplicates
*~**/
template <class T>
bool HashTable<T>::insert(const T &value, int h(const T &key, int size))
{
    HashNode<T> *bucket;
    int index, stop, noCol;

    // initalize to 0
    noCol = 0;

    if (count == hashSize)
        return false;

    // stop when we loop back to the same index we started on
    index = stop = h(value, hashSize);

    do
    {
        bucket = hashAry + index % hashSize;
        if (!bucket->isOccupied())
        {
            bucket->setItem(value);
            bucket->setTouched(true);
            bucket->setOccupied(1);
            bucket->setNoCollisions(noCol);
            count++;
            return true;
        }

        // reject duplicates
        if (bucket->getItem() == value)
        {
            return false;
        }
        noCol++;
    } while (stop != ++index % hashSize);

    return false;
}

/*~*~*~*
   Removes the item with the matching key from the hash table
     - copies data in the hash node to itemOut
     - replaces data in the hash node with an empty record
*~**/
template <class T>
bool HashTable<T>::remove(T &itemOut, const T &key, int h(const T &key, int size))
{
    HashNode<T> *bucket;
    int index, stop;

    if (count == 0)
        return false;

    // stop when we loop back to the same index we started on
    index = stop = h(key, hashSize);

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
        if (bucket->getItem() == key)
        {
            T empty;
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
template <class T>
int HashTable<T>::search(T &itemOut, const T &key, int h(const T &key, int size))
{
    HashNode<T> *bucket;
    T item;
    int index, stop;

    if (count == 0)
        return false;

    // stop when we loop back to the same key we started on
    index = stop = h(key, hashSize);

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

        if (item == key)
        {
            itemOut = item;
            return bucket->getNoCollisions();
        }

    } while (stop != ++index % hashSize);

    return -1;
}

#endif // HASHTABLE_H_
