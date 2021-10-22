#include "BinarySearchTree.h"  // BST ADT
#include <iostream>
#include <string>

using namespace std;

void buildBST(int n, BinarySearchTree<int> &);
void hDisplay(int &);
void vDisplay(int &);


int main()
{
    BinarySearchTree<int> bst;
    
    int n;
    char option;
    
    cout << "What is the number of nodes in the BST? " << endl;
    cin >> n;
    cout << "What traversal[prE/posT]? " << endl;
    cin >> option;
    
    buildBST(n, bst);
    
    cout << "  Inorder: ";
    bst.inOrder(hDisplay);
    cout << endl;
    if ( option == 'T' || option == 't')
    {
        cout << "Postorder: ";
        bst.postOrder(hDisplay); // passing hDisplay to postOrder
        cout << endl;
        bst.postOrder(vDisplay); // passing vDisplay to postOrder
        cout << endl;
    }
    if ( option == 'E' || option == 'e')
    {
        cout << " Preorder: ";
        bst.preOrder(hDisplay);  // passing hDisplay to preOrder
        cout << endl;
        bst.preOrder(vDisplay);  // passing vDisplay to preOrder
        cout << endl;
    }
            
    return 0;
}  

/*
 buildBST: builds a binary search tree
 of integers
*/
void buildBST(int n, BinarySearchTree<int> &bst)
{
    int item;
    
    while(n--)
    {
        item = rand( ) % 30 + 10;
        bst.insert(item);
    }
}

/*
 horizontal display: all items on one line
*/
void hDisplay (int &item)
{
    cout << item << " ";
}

/*
 vertical display: one item per line
*/
void vDisplay (int &item)
{
    cout << item << endl;
}

