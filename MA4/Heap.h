//***************************************************************************//
//**
//**  Simple Heap implementation
//**
//***************************************************************************//

#ifndef __HEAP_H
#define __HEAP_H
#include <iostream>
#include <vector>
#include <stdexcept>      // std::out_of_range
#include <math.h>         // pow()
#include <string>
#include <limits>
#include <bits/stdc++.h>

/**
 *  Declaring Heap class
 */
template<typename T>
class Heap
{

private:
	long unsigned int num_items;
	std::vector<T> _items;    // Main vector of elements for heap storage. The first item in the array is a placeholder.

/*********************************************************************/
/********************* Start Microassignment zone ********************/

	/**
	 *  Percolates the item specified at by index down 
     *   into its proper location within a heap.
	 *  Used for dequeue operations and array to heap conversions
	 *  MA TODO: Implement percolateDown
	 */
	void percolateDown(unsigned int hole)
	{
		unsigned int parent = hole;
		unsigned int child = hole << 1;
		while(child <= num_items) {
			if(_items[child] > _items[child + 1]) {
				++child;
			}
			if(_items[parent] <= _items[child]) {
				break;
			}
			T temp = _items[parent];
			_items[parent] = _items[child];
			_items[child] = temp;
			parent = child;
			child = child << 1;
		}
    }


	/**
	 *  Add a new item to the end of the heap and percolate up this item to fix heap property
	 *  Used in inserting new nodes into the heap
	 *  MA TODO: Implement percolateUp
	 */
	void percolateUp(T item)
	{
		_items[++num_items] = item;
		long unsigned int idx = num_items;
		long unsigned int parent = idx >> 1;
		while(parent != 0 && _items[idx] < _items[parent]) {
			T temp = _items[idx];
			_items[idx] = _items[parent];
			_items[parent] = temp;
			idx = parent;
			parent = parent >> 1;
		}
		if(num_items == _items.size() - 1) {
			_items.resize(_items.size() << 1);
		}
	}

/********************** End Microassigment zone *********************/

public:
	/**
	 *  Default empty constructor
	 */
	Heap() {
		// items[0] = -infinity
		_items = std::vector<T>(15);
		_items[0] = INT_MIN;
		this->num_items = 0;
	}


	/**
	 *  Adds a new item to the heap
	 */
	void push(T item)
	{
		percolateUp(item);
	}

	/**
	 *  Removes minimum value from heap 
	 */
	T pop()
	{

		if( this->num_items == 0 ) {
			throw std::out_of_range("pop() - No elements in heap");
		}

		T minItem = _items[1];

		_items[1] = _items[num_items--]; // Move last item to root

		if( num_items > 0 ) {			// Only runs if the heap isn't empty now
			percolateDown(1);       // Fix heap property
		}
        return minItem;
	}


	/**
	 *  Returns true if heap is empty, else false
	 *  Consider the first placeholder in the array
	 */
	bool empty() const
	{
		return this->num_items == 0 ? false : true;
	}

	/**
	 *  Returns current quantity of elements in heap (N)
	 *  Consider the first placeholder in the array
	 */
	long unsigned int size() const
	{
		return this->num_items;
	}


	/**
	 *  Return heap data in order from the _items vector
	 */
	std::string to_string() const
	{
		std::string ret = "";
		for(unsigned int i = 1; i < _items.size(); i++)
     	{
			ret += std::to_string(_items[i]) + " ";
		}
		return ret;
	}
};

#endif
