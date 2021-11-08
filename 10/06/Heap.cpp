/* *~*~*
Implementation file for the Heap class: max-heap of integers
Written By: A. Student
Changed by: Noah Cardoza
IDE: VS Code
*~**/

#include "Heap.h"

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
void Heap::_reHeapUp(int index)
{
	if (index) // means lastndx != 0, i.e. newElement is not heap's root
	{
		int parent = _findParent(index);
		if (heapAry[parent] < heapAry[index])
		{
			swap(heapAry + parent, heapAry + index);
			_reHeapUp(parent);
		}
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int index)
{
	int right = _findRightChild(index);
	int left = _findLeftChild(index);

	int direction = 
		left == -1 
			? right
			: heapAry[left] > heapAry[right]
				? left
				: right;

	if (direction != -1 && heapAry[index] < heapAry[direction])
	{
		swap(heapAry + index, heapAry + direction);
		return _reHeapDown(direction);
	}
}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem)
{
	if (isFull())
		return false;

	heapAry[count] = newItem;

	_reHeapUp(count++);

	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem)
{
	if (isEmpty())
		return false;

	returnItem = heapAry[0];
	heapAry[0] = heapAry[--count];

	_reHeapDown(0);

	return true;
}