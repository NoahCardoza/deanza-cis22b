/*~*~*~*
 CIS 22C
 Homework 5
 
 Written By: A. Student
 Changed by:
*~**/

#include <iostream>

#include "HashTable.h"

using namespace std;

int main()
{
 
    Student list[] = {{"Tom", 2.5}, {"Bob", 3.2}, {"Boc", 3.2}, {"Linda", 3.9}, {"Tim", 4.0},
        {"Vic", 3.9}, {"Ann", 3.5}, {"Dylan", 3.1}, {"obB", 2.2}, {"oBb", 3.7},
        {"Bbo", 3.3}, {"bBo", 3.9}, {"boB", 2.3}, {"", 0}};
    
    HashTable hash;
    
    // build hash from array
    for (int i = 0; list[i].getName() != ""; i++)
    {
        hash.insert(list[i]);
    }
    
        
    // test search
    string target[] = {"Ann", "Daria","Tom", "Bob","Boc", "Linda", "Julia",
                       "Dylan", "obB", "oBb", "Bbo", "bBo", "boB", ""};
    
    for (int i = 0; target[i] != ""; i++)
    {
        Student item;
        int nc;
        if ((nc = hash.search(item, target[i])) != -1)
        {
            cout << item.getName() << " " << item.getGpa() << " (" << nc << " collisions!)" << endl;
        }
        else
            cout << target[i] << " not found!" << endl;
            
    }
    
    cout << "Load Factor: " << hash.getLoadFactor() << endl;
    
    // test delete
    cout << "Test delete" << endl;
    cout << "Enter name or Q to quit: ";
    string name;
    cin >> name;
    while ( name != "Q" )
    {
        Student itemOut, found;
        if (hash.remove(itemOut, name))
            cout << endl << itemOut.getName() << " " << itemOut.getGpa() << " - deleted!" << endl;
        else
            cout << name << " - not found!" << endl;
   
        cout << "Load Factor: " << hash.getLoadFactor() << endl;
    
        cout << "Enter name or Q to quit: ";
        cin >> name;
    }
    
    // test search
     cout << "Test search" << endl;
     cout << "Enter name or Q to quit: ";
     cin >> name;
     while ( name != "Q" )
     {
         Student found;
                
         if ((hash.search(found, name)) != -1)
             cout << endl << "Found: " << found.getName() << " " << found.getGpa() << endl;
         else
             cout << endl << name << " not found!" << endl;
         cout << "Enter name or Q to quit: ";
         cin >> name;
     }
    
    // Add a new item to the hash table: regject duplicates
       cout << "Test hash search/insert" << endl;

       Student found;
       double gpa;
       cout << "Enter name or Q to quit: ";
       cin >> name;
       while ( name != "Q" )
       {
           if (hash.search(found, name) != -1)
               cout << endl << "Duplicate key: " << found.getName() << " - rejected! " << endl;
           else
           {
               cout << "Enter gpa ";
               cin >> gpa;
               Student item(name, gpa);
               hash.insert(item);
               cout << name << " - inserted (" << hash.search(found, name) << " collisions)" << endl;
           }
           cout << "Enter name: ";
           cin >> name;
       }
       cout << "Load Factor: " << hash.getLoadFactor() << endl;
    
    return 0;
}
