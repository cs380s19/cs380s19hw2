//********************************************************
// File name:  Student.cpp
// Author:     Chadd Williams, edited Chris Lane 1/29/2019
// Date:       7/5/2013
// Class:      CS380
// Assignment: HW 2: Basic Sorting
// Purpose:    To define the implementation of a Student
//********************************************************

#include "Student.h"
#include <iomanip>

//********************************************************
// Constructor: Student
//
// Description: Initialize data members.
//
// Parameters: none
//
// Returned:	 none
//		
//********************************************************
Student::Student() {
};

//********************************************************
// Constructor: Student
//
// Description: Initialize data members.
//
// Parameters: id, first name, last name
//
// Returned:	 none
//		
//********************************************************
Student::Student(int id, std::string fname, std::string lname) {
	mStudentID = id;
	mFName = fname;
	mLName = lname;
}

//********************************************************
// Destructor: Student
//
// Description: delete data members.
//
// Parameters: none
//
// Returned:	 none
//		
//********************************************************
Student::~Student() {
}

// ComparableItem

//********************************************************
// Method:	operator< 
//
// Description: Compare student IDs of two Students
//
// Parameters: A student to compare against this student
//
// Returned: true if this student's ID is less than right's ID
//	
//********************************************************
bool Student::operator< (const ComparableItem &right) const {
	return mStudentID < dynamic_cast<const Student*>(&right)->mStudentID;
}

//********************************************************
// Method:	operator> 
//
// Description: Compare student IDs of two Students
//
// Parameters: A student to compare against this student
//
// Returned: true if this student's ID is greater than right's ID
//	
//********************************************************
bool Student::operator> (const ComparableItem &right) const {
	return mStudentID > dynamic_cast<const Student*>(&right)->mStudentID;
}

//********************************************************
// Method:	operator==
//
// Description: Compare student IDs of two Students
//
// Parameters: A student to compare against this student
//
// Returned: true if this student's ID is equal to right's ID
//	
//********************************************************
bool Student::operator== (const ComparableItem &right)const {
	return mStudentID == dynamic_cast<const Student*>(&right)->mStudentID;
}

// Friends

//********************************************************
// Method:	operator <<
//
// Description: Output operator
//
// Parameters: Output Stream, Student
//
// Returned: The Output Stream
//	
//********************************************************
std::ostream& operator << (std::ostream &os, const Student &student) {
	os << std::setw(8) << std::left << student.mStudentID
		<< student.mFName << " " << student.mLName;
	return os;
}

//********************************************************
// Method:	operator>>
//
// Description: Input operator
//
// Parameters: Input Stream, Student
//
// Returned: The Input Stream
//	
//********************************************************
std::istream& operator >> (std::istream &is, Student &student) {
	is >> student.mStudentID >> student.mFName >> student.mLName;
	return is;
}