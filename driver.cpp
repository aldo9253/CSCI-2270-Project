// Alex Doner & E.O. Rafelson
// CSCI 2270 Project
// driver.cpp
//

#include "miniGit.hpp"
#include<iostream>
using namespace std;

int main() {

	//print menu
	cout << "Welcome to miniGit" << endl;
	cout << "Please press: " << endl;
	cout <<  "1: to initialize the repository" << endl;
	cout <<  "2: to add a file to the repository" << endl;
	cout <<  "3: to commit a file to the repository" << endl;
	cout <<  "4: to initialize the repository" << endl;
	cout <<  "5: to initialize the repository" << endl;
	cout <<  "6: to initialize the repository" << endl;
	cout <<  "x: to exit the program" << endl;

	//cout << input << endl;
	bool exit = true;
	char input; //char will take the 1st char, string takes the 1st word, only returns on enter
	//while (input != 'x') {
	while (exit) {

		// Take user input;
		cin >> input;
		switch(input) {
			case '1':
				cout << "You pressed '1' " << endl;
				// put function call here
				break;
			case '2':
				cout << "You pressed '2' " << endl;
				break;
			case '3':
				cout << "You pressed '3' " << endl;
				break;
			case '4':
				cout << "You pressed '4' " << endl;
				break;
			case '5':
				cout << "You pressed '5' " << endl;
				break;
			case '6':
				cout << "You pressed '6' " << endl;
				break;
			case 'x': 
				cout << "Come again soon" << endl;
				exit  = false;
				return 0;
			default:
				cout << "Please select an appropriate option and try again." << endl;
		} // end switch
	} // end while
	return 0;
} // end main



