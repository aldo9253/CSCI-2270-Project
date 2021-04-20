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

//#ifdef miniGet_HPP
//#define miniGet_HPP
#include<vector>
#include<iostream>
#include<fstream> // will need for file stuff?
#include<sstream> // what do?

using namespace std;

struct singlyNode{
	string fileName; 	// Name of local file
	string fileVersion;	// Name of file in the .minigit folder
	singlyNode * next;
}; // end doublyNode	

struct doublyNode{
	int commitNumber;
	singlyNode * fileHead; //fileHead
	doublyNode * prev;
	doublyNode * next;
}; // end doublyNode	

class miniGit{
	private:
		doublyNode * commitHead;
	public:
		miniGit();
		~miniGit();
        void init();
		void addFile(); // add nodes to point to files/filename
		void removeFile(); // delete node from singly linked list
		void checkOut(); // overwrite local files with files in repo
		void commit(); // create new node in double linked list, and compare, update version #'s, etc...
		
		// Some basic functions to traverse the doubly linked list
		// " " singly linked list
		// Some function to compare files (for version info)
		
		// Hash table search // for phase two
		//
};



