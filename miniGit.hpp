// Alex Doner & E.O. Rafelson
// Data Structures 2270
// Final Project
//
//
// Core features to keep in mind
// 	- adding new files to the current commit
// 	- removing files from the current commit
// 	- commiting changes
// 	- checking out a specific version based on a unique commit number
// 	
// 	See the Project document for specifics

#ifdef miniGet_HPP
#define miniGet_HPP
#include<vector>
#include<iostream>
#include<fstream> // will need for file stuff
#include<cstream> // what do?
#include<sstream> // what do?

using namespace std;

struct doublyNode{
	int commitNumber;
	singlyNode * head;
	doublyNode * previous;
	doublyNode * next;
}; // end doublyNode	

struct singlyNode{
	string fileName; 	// Name of local file
	string fileVersion;	// Name of file in the .minigit folder
	singlyNode * next;
}; // end doublyNode	

class miniGit{
	private:
		doubleNode * head;
	public:
		miniGit();
		~miniGit();
		void addFile();
		void removeFile();
		void checkOut();
		void commit();
		

		//Hash table search
		//
};



