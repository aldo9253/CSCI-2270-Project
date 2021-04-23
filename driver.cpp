// Alex Doner & E.O. Rafelson
// CSCI 2270 Project
// driver.cpp
//

#include "miniGit.hpp"
#include<iostream>
#include<string>

using namespace std;

void printMenu(){
	//print menu
	cout << endl;
	cout << "Please press: " << endl;
	cout <<  "1: to add a file" << endl;
	cout <<  "2: to remove a file" << endl;
	cout <<  "3: to commit" << endl;
	cout <<  "4: to checkout" << endl;
	//cout <<  "5: to checkOut" << endl;
	//cout <<  "6: to print Singly Nodes" << endl;
	cout <<  "x: to exit the program" << endl << endl;
} // end printMenu

int main() {
	cout << endl <<  "Welcome to miniGit" << endl << endl;
	//printMenu();
	//cout << input << endl;
	cout << "Press 0 to initialize the repository" << endl;
	bool exit = true;
	bool init = false;
	char input; //char will take the 1st char, string takes the 1st word, only returns on enter
    miniGit * repo = new miniGit;
	while (exit) {
		// Take user input;
		cin >> input;
		switch(input) {
			case '0':
				if(!init) { 
					repo->init();
                	cout << "Repository Initialized" << endl;
					init = true;
				} else {
                	cout << "Repository Already Initialized" << endl;
				}
                printMenu();
				break;
			case '1':
                repo->addFile();
                printMenu();
				break;
			case '2':
                repo->removeFile();
                printMenu();
				break;
			case '3':
				repo->commit();
				printMenu();
				break;
			case '4':
				repo->checkOut();
				printMenu();
				break;
			//case '5':
				//cout << "You pressed '5' " << endl;
                ////repo->checkOut();
				//printMenu();
				//break;
			//case '6':
				//cout << "You pressed '6' " << endl;
				//repo->printSingly();
				//printMenu();
				//break;
			case 'x': 
				cout << "Come again soon" << endl;
				exit  = false;
				repo->~miniGit();
				return 0;
			default:
				cout << "Please select an appropriate option." << endl;
		} // end switch
	} // end while
	return 0;
} // end main



