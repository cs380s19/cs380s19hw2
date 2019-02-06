//********************************************************
// File name:  Student.h
// Author:     Chadd Williams - edited by Chris Lane
// Date:       7/5/2013 - 1/29/2019 
// Class:      CS380
// Assignment: HW 2 Basic Sorting
// Purpose:    To define the header file for an item that represents
//						 a student.
//********************************************************

#ifndef _Student_H_
#define _Student_H_
#include "ComparableItem.h"
#include <iostream>
#include <string>

class Student : public ComparableItem{
public:
	// constructor that sets the studentID, first name, and last name
	Student(int id, std::string fname, std::string lname);

	// empty constructor
	Student();

	// destructor. Nothing to deallocate but is marked virtual to
	// allow subclasses to deallocate data.
	virtual ~Student();

	// ComparableItem iterface
	virtual bool operator< (const ComparableItem &right) const;
	virtual bool operator> (const ComparableItem &right) const;
	virtual bool operator== (const ComparableItem &right) const;

	// input and output operators
	friend std::ostream& operator << (std::ostream &os, const Student &student);
	friend std::istream& operator >> (std::istream &is, Student &student);

private:
	int mStudentID;
	std::string mFName;
	std::string mLName;
};
#endif