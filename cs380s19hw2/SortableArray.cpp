//********************************************************
// File name:  SortableArray.cpp
// Author:     Chadd Williams - edited by Chris Lane
// Date:       7/5/2013 - 1/30/2019
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    Implementation for SortableArray
//********************************************************

#include "SortableArray.h"
#include <vector>

typedef std::vector<ComparableItem*> VectorData;

//typecasts from void* to VectorData* then dereferences the pointer
#define ARRAY (*((VectorData*)m_arrayData))

//********************************************************
// Constructor: SortableArray
//
// Description: Initialize data members.
//
// Parameters: none
//
// Returned:	 none
//		
//********************************************************
SortableArray::SortableArray(){
	m_arrayData = new VectorData;
}

//********************************************************
// Method:	deallocateItems
//
// Description: deallocate all items pointed to by the array
//
// Parameters: none
//
// Returned: none
//	
//********************************************************
void SortableArray::deallocateItems(){
	for (unsigned int i = 0; i < ARRAY.size(); i++){
		ComparableItem *pItem = ARRAY[i];
		delete pItem;
		ARRAY[i] = NULL;
	}
}

//********************************************************
// Destructor:	SortableArray
//	
// Description: Deallocate data members
//	
//********************************************************
SortableArray::~SortableArray(){
	delete (VectorData*)m_arrayData;
}

//********************************************************
// Method:	count
//
// Description: return the number of elements in the array
//
// Parameters: none
//
// Returned: the number of elements
//	
//********************************************************
int SortableArray::count() const {
	return (int)ARRAY.size();
}

//********************************************************
// Method:	pushBack
//
// Description: add an int to the end of the array
//
// Parameters: val - the int to add
//
// Returned: none
//	
//********************************************************
bool SortableArray::pushBack(ComparableItem *pVal){
	ARRAY.push_back(pVal);
	return true;
}

//********************************************************
// Method:	getItem
//
// Description: get an item at a given location
//
// Parameters: index -  the index of the item
//
// Returned: the item, or NULL on error
//	
//********************************************************
ComparableItem* SortableArray::getItem(int index){
	if (static_cast<unsigned int>(index) >= ARRAY.size() || index < 0){
		return NULL;
	}
	return ARRAY[index];
}

//********************************************************
// Method:	setItem
//
// Description: set an item at a given location
//
// Parameters: index -  the index of the item
//							pItem - the item
//
// Returned: true on success, false on failure
//	
//********************************************************
bool SortableArray::setItem(int index, ComparableItem* pItem){
	if (static_cast<unsigned int>(index) >= ARRAY.size() || index < 0){
		return false;
	}
	ARRAY[index] = pItem;
	return true;
}

//********************************************************
// Method:	clear
//
// Description:  empty the array
//
// Parameters: none
//
// Returned: none
//	
//********************************************************
void SortableArray::clear(){
	ARRAY.clear();
}

//********************************************************
// Method:	operator<<
//
// Description:  Provide an << operator.
//
// Parameters: std::ostream &os - the stream to write to
//						 const SortableArray &array - the array to write
//
// Returned: the ostream written to
//	
//********************************************************
std::ostream & operator << (std::ostream &os, const SortableArray &array){
	for (int i = 0; i < array.count(); i++)	{
		os << (*((VectorData*)array.m_arrayData))[i] << "\n";
	}
	return os;
}