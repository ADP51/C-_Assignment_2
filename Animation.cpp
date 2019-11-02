/************************************************
Filename:Animation.cpp
Version: 1.0
Author: Andrew Palmer
Assignment Number:0
Assignment Name:Animation Project in C
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Mariusz Makos
Due Date: 2019/10/12
Submission Date:2019/10/12
List of source files: Animation.cpp
Purpose: Until the User quits the program. It will read a valid response from the keyboard
in order to go through the process of either creating a frame of animation,editing a frame,
displaying all frames or even delete a frame.
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
Function name:	DeleteFrame
Purpose:		Deletes a frame from the beginning of the
				Animation's frames list.
In parameters:
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
void Animation::DeleteFrame() {
	this->frames.pop_front();
}

/***********************************************
Function name:	EditFrame
Purpose:		Edits the name of a frame.
In parameters:
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
void Animation::EditFrame()
{
	int counter = 0;
	int index;
	string newName;
	int newDuration;

	// count how many frames in the list
	for (auto i = this->frames.begin(); i != this->frames.end(); ++i) {
		counter++;
	}

	cout << "Edit a Frame in the Animation" << endl;
	cout << "There are " << counter << " Frame(s) in the list. Please specify the index (from 0 to " << counter - 1 <<") to edit at:" << endl;
	cin >> index;

	counter = 0;

	for (Frame& frame : frames) {
		if (counter = index) {
			cout << frame << " What do you wish to replace them with?" << endl;
			cin >> newName;
			cin >> newDuration;
			newName = newName + '\0';
			char* name = new char[newName.length()];
			newName.copy(name, newName.length(), 0);
			Frame newFrame(name, newDuration);
			frame = newFrame;
		}
	}
}

/***********************************************
Overloading the >> operator
Purpose:		Defines the new behaviour when passing
				the Animation object to instream.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
istream& operator>>(istream& in, Animation& animation) {
	string name;
	int duration = 0;
	cout << "Insert a Frame into the Animation " << endl;
	cout << "Please enter the Frame frameName: " << endl;
	cin >> name;
	cout << "Please enter the Frame duration: " << endl;
	cin >> duration;
	name = name + '\0';
	char* newName = new char[name.length()];
	name.copy(newName, name.length(), 0);
	Frame newFrame(newName, duration);
	animation.frames.emplace_front(newFrame);
	return in;
}

/***********************************************
Overloading the << operator
Purpose:		Defines the new behaviour when passing
				the Animation object to outstream.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
ostream& operator<<(ostream& out, Animation& animation) {
	int counter = 0;
	out << "Animation name is " << animation.animationName << endl;
	out << "Report the Animation" << endl;
	
	if (animation.frames.empty()) {
		out << "No frames in the Animation" << endl;
	}
	else {
		for (Frame& frame : animation.frames) {
			out << "Frame " << counter << ": " << frame << endl;
			counter++;
		}
	}
	return out;
}


