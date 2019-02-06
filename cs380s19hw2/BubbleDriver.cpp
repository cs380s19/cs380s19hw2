//********************************************************
// File name:  BubbleDriver.cpp
// Author:     Chadd Williams - edited by Shereen Khoja
// Date:       7/5/2013 - 2/1/2015
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    Driver to test BubbleSort using Students
//********************************************************

#define MEM_DEBUG 1
#include "mem_debug.h"

#include "SortableArray.h"
#include "BubbleSort.h"
#include "Student.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void printArray(SortableArray &theArray);

//********************************************************
// Method:	main
//
// Description: create an array of Students, sort the array, print the array.
//
// Parameters: none
//
// Returned: int - success or failure (-1)
//	
//********************************************************
int main(){
#ifdef MEM_DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// _crtBreakAlloc = 131; // optionally break at a particular mem alloc.
#endif

	const std::string FILE_NAME = "students.txt";
	Student *pStudent;

	// Create a BubbleSortArray object
	SortableArray theArray;
	std::ifstream inFile;

	inFile.open(FILE_NAME);

	if (!inFile) {
		std::cout << "ERROR: Could not open" << FILE_NAME << "\n\n";
		exit(-1);
	}

	// read students into the array
	while (!inFile.eof())	{
		pStudent = new Student();
		inFile >> *pStudent;
		theArray.pushBack(pStudent);
	}
	inFile.close();

	// output the array
	std::cout << "\nArray data before sorting:\n\n";
	printArray(theArray);

	// Sort the array
	BubbleSort *pBubbleSort = new BubbleSort();
	theArray.setSortBehavior(pBubbleSort);

	theArray.sort();

	// output the array
	std::cout << "\nArray data after ASC sorting:\n\n";
	printArray(theArray);

	// Sort the array in DESC order
	pBubbleSort->setSortDirection(SortAlgorithm::DESC);
	theArray.sort();

	// output the array
	std::cout << "\nArray data after DESC sorting:\n\n";
	printArray(theArray);

	std::cout << "\n" << pBubbleSort->name() << "\n\n";

	// delete the items pointed to by the array
	theArray.deallocateItems();

	// delete the sort object
	delete pBubbleSort;

	system("pause");

	return EXIT_SUCCESS;
}

//********************************************************
// Method:	printArray
//
// Description: Walk through the array an print each item
//
// Parameters: A SortableArray to be printed
//
// Returned: none
//	
//********************************************************
void	printArray(SortableArray &theArray){
	Student *pStudent;
	for (int i = 0; i < theArray.count(); i++){
		pStudent = dynamic_cast<Student*> (theArray.getItem(i));
		std::cout << *pStudent << "\n";
	}
}