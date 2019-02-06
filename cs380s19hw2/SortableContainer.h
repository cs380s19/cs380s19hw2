//********************************************************
// File name:  SortableContainer.h
// Author:     Chadd Williams - edited by Chris Lane
// Date:       7/5/2013 - 1/29/2019
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    To define the header file for a Sortable container.
//						 any container that wants to use the SortAlgorithm
//						 classes must implement this class.
//********************************************************

#ifndef _SortableContainer_H_
#define _SortableContainer_H_
#include <cstddef>

// This is weird syntactic sugar since
// SortAlgorithm and SortableContainer need to
// reference each other.
class SortAlgorithm;
#include "ComparableItem.h"
#include "SortAlgorithm.h"

class SortableContainer {
	public:
		//This is the abstract class for the SortableContainer.

		//The SortableContainer provides a get/set interface
		//using array-like indexing (0 to n-1 for an n element
		//list).  The backing store of a SortableContainer can be
		// any data structure that can provide access to data items
		// via integer indexes.

		//The SortableContainer will only contain pointers to 
		//ComparableItems.  To make a class suitable for storage
		//in a SortableContainer, have that class subclass ComparableItem.


		// The virtual destructor is provided to allow subclasses
		// the ability to define a destructor to deallocate memory
		// the SortableContainer destructor does nothing.
		//
		// Any object allocated by the user remain the user's responsibility
		// to deallcate, even after a pointer to those objects are stored in
		// a SortableContainer.
		//
		// The class holds a pointer to a SortAlgorithm.  This SortAlgorithm
		// is not deallocated by SortableContainer. It is the user's responsiblity
		// to deallocate the SortAlgorithm.
		virtual ~SortableContainer() {};

		// default constructor
		SortableContainer() { mpSortBehavior = NULL; };

		// get and set an item

		// return NULL on error
		virtual ComparableItem * getItem(int index) = 0;

		// return false on error
		virtual bool setItem(int index, ComparableItem *pItem) = 0;


		// adds a new element to the back of the container
		// return false on error
		virtual bool pushBack(ComparableItem *val) = 0;

		// The SortableContainer contains only pointers, no actual objects.
		// If the user wants the SortableContainer to deallocate the objects,
		// call deallocateItems.
		//
		// deallocateItems is a convienence method that will deallocate all
		// objects pointed to by a pointer in the container.
		//
		// If deallcoateItems is not called, the objects will not be deallocated
		// and it will be the responsibility of the user to deallocate the objects.
		virtual void deallocateItems() = 0;

		// returns the number of elements in the array
		virtual int	count() const = 0;

		// clears the container. No objects whose pointers are stored
		// in the contain are deallocated.
		virtual void clear() = 0;

		// set the sort algorithm for this container
		void setSortBehavior(SortAlgorithm *sortAlgorithm)
		{
			mpSortBehavior = sortAlgorithm;
		};

		// invoke the sort algorithm on the container
		virtual void sort();

	private:
		SortAlgorithm *mpSortBehavior;
};
#endif