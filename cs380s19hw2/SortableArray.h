//********************************************************
// File name:  SortableArray.h
// Author:     Chadd Williams - edited by Chris Lane
// Date:       7/5/2013 - 1/29/2019 
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    To define the header file for a sortable array
//						 This inherits from SortableContainer so that
//						 SortAlgorithm can be used to sort this container.
//********************************************************

#ifndef _SortableArray_H_
#define _SortableArray_H_
#include <iostream>
#include "SortableContainer.h"
#include "SortAlgorithm.h"

class SortableArray : public SortableContainer {
	public:
		// SortableArray is a concrete implementation of SortableContainer
		// this array is backed by an stl vector

		// constructor
		SortableArray();

		// destructor
		virtual ~SortableArray();

		// adds a new element to the back of the array
		virtual bool pushBack(ComparableItem *val);

		// SortableContainer
		// returns the number of elements in the array
		virtual int	count() const;

		// returns the ith element of the array
		// virtual ComparableItem * operator [](int index);
		virtual ComparableItem * getItem(int index);
		virtual bool setItem(int index, ComparableItem *pItem);
		virtual void deallocateItems();

		//////////////////////

		// clears the array 
		virtual void clear();

		friend std::ostream & operator << (std::ostream &os, const SortableArray &array);

	private:
		// opaque pointer to an array object
		void * m_arrayData;
};
#endif