/* *~*~*
Specification file for the Heap class:  heap of integers
Written By: A. Student
Changed by:
IDE:  
*~**/

#ifndef HEAP_H_
#define HEAP_H_

#include <math.h>
#include <algorithm>

int heightFromIndex(int n)
{
	return floor(log2(n + 1));
}

template <class T>
class Heap
{

	typedef int (*cmp_t)(T *, T *);
	typedef void (*visit_t)(T *, T);

private:
	T *heapAry;
	int heapSize;
	int count;

	/* *~*~*
		The private member function _reHeapUp rearranges the heap after insert by moving the
		last item up to the correct location in the heap
	 *~**/
	void _reHeapUp(int index, cmp_t cmp)
	{
		if (index) // means lastndx != 0, i.e. newElement is not heap's root
		{
			int parent = _findParent(index);
			if (cmp(heapAry + parent, heapAry + index) == 1)
			{
				std::swap(heapAry[parent], heapAry[index]);
				_reHeapUp(parent, cmp);
			}
		}
	}

	/* *~*~*
		The private member function _reHeapDown rearranges the heap after delete by moving the
		data in the root down to the correct location in the heap
	*~**/
	void _reHeapDown(int index, cmp_t cmp)
	{
		int right = _findRightChild(index);
		int left = _findLeftChild(index);

		int direction =
				right == -1
						? left
				: cmp(heapAry + left, heapAry + right) == -1
						? left
						: right;

		if (direction != -1 && cmp(heapAry + index, heapAry + direction) == 1)
		{
			std::swap(heapAry[index], heapAry[direction]);
			return _reHeapDown(direction, cmp);
		}
	}

	int _findParent(int index) { return (index <= 0) ? (-1) : (index - 1) / 2; }

	int _findLeftChild(int index) { return (2 * index + 1 >= count) ? (-1) : (2 * index + 1); }

	int _findRightChild(int index) { return (2 * index + 2 >= count) ? (-1) : (2 * index + 2); }

	void _printIndented(int index, visit_t visit)
	{

		int left = _findLeftChild(index);
		int right = _findRightChild(index);

		if (right != -1)
		{
			_printIndented(right, visit);
		}

		visit(heapAry + index, heightFromIndex(index));

		if (left != -1)
		{
			_printIndented(left, visit);
		}
	}

public:
	Heap()
	{
		count = 0;
		heapSize = 128;
		heapAry = new T[heapSize];
	}

	~Heap() { delete[] heapAry; }

	int getCount() const { return count; }
	int getSize() const { return heapSize; }
	bool isEmpty() const { return count == 0; }
	bool isFull() const { return count == heapSize; }

	/* *~*~*
		The public member function insertHeap inserts a new item into a heap.
		It calls _reheapUp.
	*~**/
	bool insertHeap(T item, cmp_t cmp)
	{
		if (isFull())
			return false;

		heapAry[count] = item;

		_reHeapUp(count++, cmp);

		return true;
	}

	/* *~*~*
		The public member function deleteHeap deletes the root of the heap and
		passes back the root's data. It calls _reheapDown.
 	*~**/
	bool deleteHeap(T *item, cmp_t cmp)
	{
		if (isEmpty())
			return false;

		*item = heapAry[0];
		heapAry[0] = heapAry[--count];

		_reHeapDown(0, cmp);

		return true;
	}

	/* *~*~*
		The public member function printIndented
		prints the heap as an indented tree (Right-Root-Left)
		It calls _printIndented.
	*~**/
	void printIndented(visit_t visit)
	{
		_printIndented(0, visit);
	}
};

#endif
