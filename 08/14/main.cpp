#include "BinarySearchTree.h" // BST ADT
#include "College.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <cctype> //  toupper()
#include <algorithm>

using namespace std;

void buildTree(const string &filename, BinarySearchTree<College> &tree);
void testSearchMethod(BinarySearchTree<College> &tree);

void hDisplay(College &);
void vDisplay(College &);
void iDisplay(College &, int);

string ltrim(const string &s);
string rtrim(const string &s);
string trim(const string &s);

const string WHITESPACE = " \n\r\t\f\v";

int main()
{
    string filename;
    BinarySearchTree<College> bst;

    cout << "What is the input file's name? ";
    cin >> filename;

    buildTree(filename, bst);

    char option;
    cout << "Display Inorder [Y/N]? ";
    cin >> option;
    if (toupper(option) == 'Y')
    {
        cout << endl
             << "Inorder: " << endl;
        bst.inOrder(hDisplay);
        cout << endl;
    }
    cout << "Display Indented List [Y/N]? ";
    cin >> option;
    if (toupper(option) == 'Y')
    {
        cout << "Indented List: " << endl;
        bst.printTree(iDisplay);
        cout << endl;
    }
    cout << "Display Leaf Nodes [Y/N]? ";
    cin >> option;
    if (toupper(option) == 'Y')
    {
        cout << "Leaf Nodes: " << endl;
        bst.leafIter(hDisplay);
        cout << endl;
    }

    testSearchMethod(bst);

    return 0;
}

void buildTree(const string &filename, BinarySearchTree<College> &tree)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Error opening the input file: \"" << filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(fin, line))
    {
        int rank, cost;
        string code, name;

        stringstream temp(line); // create temp with data from line
        temp >> rank;            // read from temp
        temp >> code;
        temp.ignore();            // to ignore space in front of name
        getline(temp, name, ';'); // stop reading name at ';'
        temp >> cost;

        College college(rank, code, name, cost);
        tree.insert(college);
    }

    fin.close();
}

void testSearchMethod(BinarySearchTree<College> &tree)
{
    string target;
    College search, result;

    cout << endl
         << " Search" << endl
         << "=======" << endl;

    while (42)
    {
        cout << endl
             << "Enter a college code (or Q to stop searching) : " << endl;

        getline(cin, target);
        transform(target.begin(), target.end(), target.begin(), ::toupper);
        target = trim(target);

        if (target[0] == 'Q')
        {
            break;
        }

        search.setCode(target);

        if (tree.search(search, result))
        {
            result.vDisplay();
        }
        else
        {
            cout << "College \"" << target << "\" was not found in this list." << endl;
        }
    }

    cout << "___________________END SEARCH SECTION _____" << endl;
}

/*
 horizontal display: all items on one line
*/
void hDisplay(College &item)
{
    cout << left;
    cout << " " << setw(4) << item.getCode() << "  ";
    cout << " " << setw(2) << item.getRank() << "  ";
    cout << " " << setw(27) << item.getName() << "  ";
    cout << right;
    cout << " " << setw(7) << item.getCost() << " ";
    cout << left << endl;
}

/*
 vertical display: one item per line
*/
void vDisplay(College &item)
{
    cout << "              Rank: " << item.getRank() << endl;
    cout << "       School Name: " << item.getName() << endl;
    cout << "Cost of Attendance: $" << item.getCost() << endl;
}

/*
 indented tree display: one item per line, including the level number
*/
void iDisplay(College &item, int level)
{
    for (int i = 1; i < level; i++)
        cout << "..";
    cout << level << "). " << item.getCode() << endl;
}

string ltrim(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s)
{
    return rtrim(ltrim(s));
}
