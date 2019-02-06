//********************************************************
// File name:  SortAlgorithm.h
// Author:     Chadd Williams - edited by Chris Lane
// Date:       7/5/2013 - 1/29/2019
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    To define the header file the Sort Algorithm
//********************************************************

#ifndef _SortAlgorithm_H_
#define _SortAlgorithm_H_

#include <string>
#include "ComparableItem.h"

// This is weird syntactic sugar since
// SortAlgorithm and SortableContainer need to
// reference each other.
class SortableContainer;
#include "SortableContainer.h"

class SortAlgorithm {
	public:
		// track if the sort is to be performed in 
		// ASCending or DESCending order
		enum Direction{
			ASC,
			DESC
		};

		// set the direction to sort
		void setSortDirection(Direction dir);

		// get the current sort direction
		Direction getSortDirection();

		// constructor. The default sort direction is ASC
		SortAlgorithm();

		// destructor.  Currently the destructor has no dyanmic
		// memory to deallocate.  This destructor is virtual to 
		// allow a subclass to properly deallocate dynamic memory
		virtual ~SortAlgorithm();


		// the actual sort routine. Pass a SortableContainer
		// and the data in the container will be sorted
		virtual void sort(SortableContainer &theArray) = 0;

		// provide the name of this particular sort algorthm
		virtual const std::string name() const = 0;

		// Convience function to determine, based on the sort direction, 
		// if two items need to be swapped.  
		// If the sort is ASC, then true is returned if
		// pLeft is greater than pRight.
		virtual bool needSwap(ComparableItem *pLeft, ComparableItem *pRight);

	private:
		Direction mDirection;
};
#endif