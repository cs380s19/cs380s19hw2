//********************************************************
// File name:  SortAlgorithm.cpp
// Author:     Chadd Williams - edited by Chris Lane
// Date:       7/5/2013 - 1/29/19
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    Implementation for SortAlgorithm
//********************************************************

#include "SortAlgorithm.h"

//********************************************************
// Method:	setSortDirection 
//
// Description: Set the sort direction (ASC/DESC) of this algorithm.
//
// Parameters: A Direction
//
// Returned: none
//	
//********************************************************
void SortAlgorithm::setSortDirection(SortAlgorithm::Direction dir){
	mDirection = dir;
}

//********************************************************
// Method:	getSortDirection 
//
// Description: get the sort direction (ASC/DESC) of this algorithm.
//
// Parameters: none
//
// Returned: the current sort Direction
//	
//********************************************************
SortAlgorithm::Direction SortAlgorithm::getSortDirection() {
	return mDirection;
}

//********************************************************
// Constructor: SortAlgorithm
//
// Description: Initialize data members.  Set sort Direction to ASC
//
// Parameters: none
//
// Returned:	 none
//		
//********************************************************
SortAlgorithm::SortAlgorithm() {
	mDirection = ASC;
}

//********************************************************
// Destructor: SortAlgorithm
//
// Description: Delete data members
//
// Parameters: none
//
// Returned:	 none
//		
//********************************************************
SortAlgorithm::~SortAlgorithm()
{
}

bool SortAlgorithm::needSwap(ComparableItem *pLeft, ComparableItem *pRight)
{
	return (ASC == getSortDirection() && *pLeft > *pRight) ||
		(DESC == getSortDirection() && *pLeft < *pRight);
}