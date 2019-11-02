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
Function name:	EditAnimation
Purpose:		Edit an Animation from the animations vector
				at the given index. Will display a menu
				for the edit options for that Animation
				i.e insert frame / edit frame.
In parameters:
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
void AnimationManager::EditAnimation() {
	if (this->animations.size() == 0) {
		cout << "There are no animations to edit";
	}
	else {
		int counter = 0; // the counter var for looping through the animations
		int index; // the index var to find the correct animation
		int selection = 0; // the selection for the animation menu

		cout << "Which Animation do you wish to edit? Please give the index (from 0 to " << this->animations.size() - 1 << "):";

		while (!(cin >> index)) { // make sure user input is a valid number
			cout << "That is not a number. Please try again: " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
		}

		if (index > this->animations.size() - 1 || index < 0) { // if the user selects an index out of range
			cout << "That index is out of range for this list" << endl;
		}
		else {
			cout << "Editing Animation #" << index << endl;
			for (Animation& animation : this->animations) {
				if (counter == index) { // loop through the animations until we reach the desired index
					while (selection != 4) { // loop through this menu until user quits
						cout << " 1. Insert a Frame \n 2. Delete a Frame \n 3. Edit a Frame \n 4. Quit" << endl; // the animation menu
						while (!(cin >> selection)) { // validate user input (is a number)
							cout << "That is not a number. Please try again: " << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
						}
						switch (selection) {
						case 1:
							cin >> animation;
							break;
						case 2:
							animation.DeleteFrame();
							break;
						case 3:
							animation.EditFrame();
							break;
						case 4:
							cout << "Animation #" << index << " edit complete" << endl;
							break;
						default:
							cout << "That is not a valid selection" << endl;
							break;
						}
					}
				}
				counter++; //increment counter to find the animation at the index given
			}
		}
	}
}

/***********************************************
Function name:	DeleteAnimation
Purpose:		Deletes an Animation from the animations vector 
				at the given index.
In parameters:
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
void AnimationManager::DeleteAnimation() {
	if (this->animations.size() == 0) { // check to make sure there are animations to delete
		cout << "There are no animations to delete" << endl;
	}
	else {
		int index; // the index to delete
		int size = this->animations.size() - 1; // the size of the animations vector starting at 0
		cout << "Delete an Animation from the Animation Manager" << endl;
		cout << "Which Animation do you wish to delete? Please give the index in the range 0 to " << size << ": ";

		while (!(cin >> index)) { // make sure user input is a valid number
			cout << "That is not a number. Please try again: " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
		}

		if (index <= size && index >= 0) { // validate index given
			this->animations.erase(this->animations.begin() + index); // erase the animation at the given index 
			cout << "Animation #" << index << " deleted" << endl;
		}
		else {
			cout << "Index selected is out of range" << endl;
		}
	}
}

/***********************************************
Overloading the >> operator
Purpose:		Defines the new behaviour when passing
				the AnimationManager object to outstream.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
std::istream& operator>>(std::istream& in, AnimationManager& animationManager) {
	string name;
	cout << "Add an animation to the Animation Manager" << endl;
	cout << "Please enter the Animation name: ";
	cin >> name; // take in new animation name
	Animation newAnimation(name); // create new animation object
	animationManager.animations.push_back(newAnimation); // add object to animations vector
	cout << "Animation " << name << " added at the back of animations" << endl;
	return in;
}

/***********************************************
Overloading the << operator
Purpose:		Defines the new behaviour when passing
				the AnimationManager object to outstream.
In parameters:	None
Out Parameters: None
Version:		1.0
Author:			Andrew Palmer
************************************************/
std::ostream& operator<<(std::ostream& out, AnimationManager& animationManager) {
	int counter = 0;
	out << "AnimationManager: " << animationManager.managerName << endl;
	for (Animation& animation : animationManager.animations) { 
		out << "Animation: " << counter << endl;
		out << animation; // print every animation object in the animations list
		counter++;
	}

	return out;
}