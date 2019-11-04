/************************************************
Filename:				Frame.cpp
Version:				1.0
Author:					Andrew Palmer
Assignment Number:		2
Assignment Name:		Animation in C++ using Container Classes and Overloaded Operators
Course Name:			C++
Course Code:			CST219
Lab Section Number:		302
Professor's Name:		Mariusz Makos
Due Date: 
Submission Date:		2019/11/01
List of source files:	Frame.h

Purpose:	Class file for the Frame object, defines the constructor and destructor 
			as well as the overload of the assignment and output operator.
**********************************/

#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
using namespace std;

/***********************************************
Frame Parameterized Constructor
Purpose:		Creates the Frame object and assigns
				variables.
In parameters:	frameName - the char array to assign to frameName
				duration - the int value to assign to duration
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
Frame::Frame(char* frameName, double duration){
	this->frameName = new char[strlen(frameName) + 1]; //allocate the size needed for the frameName
	strcpy_s(this->frameName, strlen(frameName) + 1, frameName); // copy the frameName to the new object
	this->duration = duration;
}

/***********************************************
Frame Copy Constructor
Purpose:		Creates the Frame object from 
				an existing Frame object.
In parameters:	copiedFrame - the Frame object to copy
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
Frame::Frame(const Frame& copiedFrame) {
	this->frameName = new char[strlen(copiedFrame.frameName) + 1]; //allocate the size needed for the frameName
	strcpy_s(this->frameName, strlen(copiedFrame.frameName) + 1 , copiedFrame.frameName); // copy the frameName to the new object
	this->duration = copiedFrame.duration;
}

/***********************************************
Frame Destructor
Purpose:		Deletes the Frame object and frees the memory held
				by it.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
Frame::~Frame() {
	delete(frameName);
}

/***********************************************
Overload of the = operator
Purpose:		Defines the new behaviour for the = operator
				for Frame objects
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
Frame& Frame::operator=(const Frame& frame)
{
	delete(this->frameName); // delete the old frameName
	this->frameName = new char[strlen(frame.frameName) + 1]; //allocate the size needed for the new name
	strcpy_s(this->frameName, strlen(frame.frameName) + 1, frame.frameName); // copy it over
	this->duration = frame.duration;
	return *this; //returns pointer to the object
}

/***********************************************
Overloading the << operator
Purpose:		Defines the new behaviour when passing 
				the Frame object to outstream.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
ostream& operator<<(ostream& out, Frame& frame) {
	out << "frameName = " << frame.frameName << "; duration = " << frame.duration;
	return out;
}