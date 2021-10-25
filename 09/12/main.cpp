
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
        if (hash.search(item, nc, target[i]))
        {
            cout << item.getName() << " " << item.getGpa() << " (" << nc << " collisions!)" << endl;
        }
        else
            cout << target[i] << " not found!" << endl;
            
    }
    
    cout << "Load Factor: " << hash.getLoadFactor() << endl;
  
    // Add a new item to the hash table;
    char option;
    cout << "Test hash insert[Y/N]? ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        string name;
        double gpa;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter gpa ";
        cin >> gpa;
        Student item(name, gpa);
        hash.insert(item);
    }
    // test search
    cout << "Test hash search[Y/N]? ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        string name;
        cout << "Enter name: ";
        cin >> name;
        Student found;
        int nc;
        if (hash.search(found, nc, name))
        {
            cout << endl << "Found: " << found.getName() << " " << found.getGpa() << " (" << nc << " collisions!)" << endl;
        }
        else
            cout << endl << name << " not found!" << endl;
    }
        
    
    
    return 0;
}
