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
	this->frameName = frameName;
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
	this->frameName = copiedFrame.frameName;
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
	delete[] frameName;
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
	delete(this->frameName);
	this->frameName = new char[strlen(frame.frameName)];
	this->duration = frame.duration;
	return *this;
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
	cout << "frameName = " << frame.frameName << "; duration = " << frame.duration << endl;
	return out;
}