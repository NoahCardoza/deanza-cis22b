/* *~*~*
Implementation file for the Heap class: min/max-heap of integers
Written By: A. Student
Changed by: Noah Cardoza
IDE: VS Code
*~**/

#include <math.h>
#include "Heap.h"

int heightFromIndex(int n)
{
	return floor(log2(n + 1));
}

/**
 * Swaps two variables
 */
template <typename T>
void swap(T *a, T *b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int index, int cmp(int, int))
{
	if (index) // means lastndx != 0, i.e. newElement is not heap's root
	{
		int parent = _findParent(index);
		if (cmp(heapAry[parent], heapAry[index]) == 1)
		{
			swap(heapAry + parent, heapAry + index);
			_reHeapUp(parent, cmp);
		}
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int index, int cmp(int, int))
{
	int right = _findRightChild(index);
	int left = _findLeftChild(index);

	int direction =
			right == -1
					? left
			: cmp(heapAry[left], heapAry[right]) == -1
					? left
					: right;

	if (direction != -1 && cmp(heapAry[index], heapAry[direction]) == 1)
	{
		swap(heapAry + index, heapAry + direction);
		return _reHeapDown(direction, cmp);
	}
}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem, int cmp(int, int))
{
	if (isFull())
		return false;

	heapAry[count] = newItem;

	_reHeapUp(count++, cmp);

	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem, int cmp(int, int))
{
	if (isEmpty())
		return false;

	returnItem = heapAry[0];
	heapAry[0] = heapAry[--count];

	_reHeapDown(0, cmp);

	return true;
}
/* *~*~*
 The public member function printIndented
 prints the heap as an indented tree (Right-Root-Left)
 It calls _printIndented.
 *~**/

void Heap::printIndented(void visit(int, int))
{
	_printIndented(0, visit);
}

void Heap::_printIndented(int index, void visit(int, int))
{

	int left = _findLeftChild(index);
	int right = _findRightChild(index);

	if (right != -1)
	{
		_printIndented(right, visit);
	}

	visit(heapAry[index], heightFromIndex(index));

	if (left != -1)
	{
		_printIndented(left, visit);
	}
}
