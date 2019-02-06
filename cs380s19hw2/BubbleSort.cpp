//********************************************************
// File name:  BubbleSort.cpp
// Author:     Chadd Williams - edited by Chris Lane
// Date:       7/5/2013 - 1/30/2019
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    To define the header file the Bubble Sort 
//********************************************************

#include "BubbleSort.h"

//********************************************************
// Method: sort
//
// Description: invoke BubbleSort on the array
//
// Parameters:  theArray - the array to sort
//
// Returned:  none
//	
//********************************************************

void BubbleSort::sort(SortableContainer &theArray){

	ComparableItem* temp;
	int count = theArray.count();

	for (int i = 0; i < count; i++){
		for (int j = count - 1; j > i; j--){
			if (needSwap(theArray.getItem(j - 1), theArray.getItem(j))){
				temp = theArray.getItem(j);
				theArray.setItem(j, theArray.getItem(j - 1));
				theArray.setItem(j - 1, temp);
			}
		}
	}
}