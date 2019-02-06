//********************************************************
// File name:  BubbleSort.h
// Author:     Chadd Williams
// Date:       7/5/2013
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    To define the header file for the Bubble Sort 
//********************************************************

#ifndef _BubbleSortAlgorithm_H_
#define _BubbleSortAlgorithm_H_

#include "SortAlgorithm.h"

class BubbleSort : public SortAlgorithm {
	public:
		void sort(SortableContainer &theArray);
		const std::string name() const { return "Bubble Sort"; };
};
#endif