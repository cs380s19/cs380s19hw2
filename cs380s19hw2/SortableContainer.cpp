//********************************************************
// File name:  SortableContainer.cpp
// Author:     Chadd Williams - edited by Chris Lane
// Date:       7/5/2013 - 1/29/2019
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    Implementation for SortableContainer
//********************************************************

#include "SortableContainer.h"

//********************************************************
// Method:	sort
//
// Description: Invoke sort algorithm on the array
//
// Parameters: none
//
// Returned: none
//	
//********************************************************
void SortableContainer::sort(){
	if (NULL != mpSortBehavior){
		mpSortBehavior->sort(*this);
	}
}