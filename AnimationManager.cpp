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
		cout << "Which Animation do you wish to edit? Please give the index (from 0 to " << this->animations.size() - 1 << "):" << endl;
		cin >> index;
		cout << "Editing Animation #" << index << endl;

		for (Animation& animation : this->animations) { 
			if (counter == index) { // loop through the animations until we reach the desired index
				while (selection != 4) { // loop through this menu until user quits
					cout << "1. Insert a Frame \n 2. Delete a Frame \n 3. Edit a Frame \n 4. Quit" << endl; // the animation menu
					cin >> selection;
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
					}
				}
				cout << "Animation #" << index << " edit complete" << endl;
			}
			counter++;
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
	if (this->animations.size() == 0) {
		cout << "There are no animations to delete";
	}
	int index;
	cout << "Delete an Animation from the Animation Manager" << endl;
	cout << "Which Animation do you wish to delete? Please give the index in the range 0 to "<< this->animations.size() << ": " << endl;
	cin >> index;
	this->animations.erase(this->animations.begin() + (index - 1)); // erase the animation at the given index 
	cout << "Animation #" << index << endl;
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
	cout << "Please enter the Animation name :" << endl;
	cin >> name;
	Animation newAnimation(name);
	animationManager.animations.push_back(newAnimation);
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
	cout << "AnimationManager: " << animationManager.managerName << endl;
	for (Animation& animation : animationManager.animations) {
		cout << animation;
	}

	return out;
}