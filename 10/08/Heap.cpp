/* *~*~*
Implementation file for the Heap class: min-heap of integers
Written By: A. Student
Changed by:
IDE:  
*~**/

#include "Heap.h"

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx)
{
	if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
	{
		int parent = _findParent(lastndx); // parent = parent of newElement
																			 // finish writing this recursive function
		/* Write  your code here */
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex)
{
	int left = _findLeftChild(rootdex);
	// finish writing this recursive function
	if (left != -1) // if there's a left child
	{
		/* Write  your code here */
	}
}

/* *~*~*
 The private member function _printIndented (recursive)
 prints the heap as an indented tree (Right-Root-Left)
 *~**/

/* Write  your code here */

/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem)
{
	// finish writing this function
	if (isFull())
		return false;
	/* Write  your code here */
	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem)
{
	// finish writing this function
	if (isEmpty())
		return false;
	/* Write  your code here */

	return true;
}

/* *~*~*
 The public member function printIndented
 prints the heap as an indented tree (Right-Root-Left)
 It calls _printIndented.
 *~**/

/* Write  your code here */
