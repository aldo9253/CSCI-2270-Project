// Alex Doner & E.O Rafelson
// CSCSI 2270 Project
// miniGit.cpp

#include "miniGit.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

miniGit::miniGit(){
  fs::remove_all(".miniGit"); // remove any old instance of the repository
  fs::create_directory(".miniGit");
} // end constructor

miniGit::~miniGit(){
  cout << "Removing Repository" << endl;
  fs::remove_all(".miniGit");
} // end destructor

void miniGit::printSingly(){
	singlyNode * curr = commitHead->fileHead;
	while (curr != nullptr) { 
		cout << "Current file name: " << curr->fileName << endl;	
		curr = curr->next;
	} // end while
} // end print

void miniGit::init(){
  commitHead = new doublyNode;
  commitHead->next = nullptr;
  commitHead->prev = nullptr;
  commitHead->fileHead = nullptr;
  commitHead->commitNumber = 0;
  checkHead = commitHead;
} // end init

//some helper functions
string getFileName(){
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // this line creates the double enter feature
    getline (cin, name);
	//cout << "string: " << name << endl;
    return name;
} // end getFileName

string getCommitNum(){
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline (cin, name);
    return name;
} // end getcommitnum

bool isNumber(const string& str){ // checks if a string is a number, used in checkout to make sure we get valid entry
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false) return false;
    }
    return true;
} // end isnumber

bool fileExist(string fileName){
    ifstream ifile;
    ifile.open(fileName);
    if(ifile)
        return true;
    else
        return false;
} // end fileExist

void miniGit::addFile(){
	// version check
	if(checkHead != commitHead) {
		cout << "You have checked out an old version" << endl;
		cout << "Check out the current version to push changes" << endl;
		cout << "Current Commit Number is: " << commitHead->commitNumber << endl;
		cout << "You have checked out version: " << checkHead->commitNumber << endl;
		return;
	}

	if (commitHead == 0) {
      cout << "miniGit repo not initialized" << endl;
	} else {
    	cout << "Please type the name of the file you wish to ADD" << endl;
    	cout << " or type 'cancel' to go back to menu" << endl;
		string fileName;
        fileName = getFileName();
        singlyNode * curr = commitHead->fileHead;
        while (curr!=0) //nullptr
        {
            if(curr->fileName == fileName)
            {
                cout << "File already exists in the commit list" << endl;
                return;
            }
            curr = curr->next;
        }
        // ADD check if file exists
        if(fileExist(fileName)){
            singlyNode* newFile = new singlyNode();
            newFile->fileName = fileName;
            newFile->fileVersion = "0";
            newFile->next = commitHead->fileHead;   
            commitHead->fileHead = newFile;         
			cout << "File node succesfully added" << endl;
		} else if (fileName == "cancel"){ // this is an extra feature
				return;
        } else {
            cout << "File doesn't exist" << endl << endl;
			cout << "Please press ENTER before typing your next attempt." << endl;
			addFile();
        } // end else if
	// this is only creating the node.
	// not actually creating the file
    return;
    }
} // end addfile

void miniGit::removeFile(){
	// version check
	if(checkHead != commitHead) {
		cout << "You have checked out an old version" << endl;
		cout << "Check out the current version to push changes" << endl;
		cout << "Current Commit Number is: " << commitHead->commitNumber << endl;
		cout << "You have checked out version: " << checkHead->commitNumber << endl;
		return;
	}

  	cout << "Please type the name of the file you wish to REMOVE" << endl;
  	string fileName = getFileName();
  	if (commitHead == 0) {
    	cout << "minigit not initialized" << endl;
  	}
  	else
  	{
    	singlyNode* curr = commitHead->fileHead;
    	singlyNode* prev = 0; // nullptr
    	while (curr != 0)
    	{
      	if (curr->fileName == fileName) {
        	if (prev != 0) {
          		prev->next = curr->next;
          		delete curr;
				cout << "File node succesfully removed" << endl;
          		return;
        	} else {
				commitHead->fileHead = curr->next;
				delete curr;
				cout << "File node succesfully removed" << endl;
				return;
        	} // end else if
      	} // end if
      		prev = curr;
      		curr = curr->next;
    	} // end while
    	cout << "File does not exist" << endl;
    	return;
  	}
} // end removefile

void file_copy(string f1name, string f2name) {
	ifstream f1(f1name); // source
	ofstream f2(f2name); // dest
	char c1;  
	if (!f1.is_open()) {
 		cout << "input file not found" << endl;
  		return;
	}
	if(!f2.is_open()) {
  		cout << "output file can't be opened" << endl;
    	return;
	}

	while(1) {
    	c1 = f1.get();
    	if(c1 == EOF) {
    		f1.close();
    		f2.close();
      		break;
    	} // end if
  		f2 << c1;
	} // end while
} // end file_copyShell

bool is_equal(string f1name, string f2name) { 
    //This function will detect even a difference in an extra line at the end
    ifstream f1(f1name), f2(f2name);
    char c1, c2;

    if(!fileExist(f1name) || !fileExist(f2name))
        return false;

    while(1) {
        c1 = f1.get();
        c2 = f2.get();

        if(c1 != c2)
            return false;
        if(c1 == EOF || c2 == EOF)
            break;
    } // end while
    return true;
} // end is_equal

void miniGit::checkOut(){

	cout << "WARNING: The checkout function will overwrite local changes." << endl;
	cout << "Please enter '-1' to return to safety" << endl;
	cout << "Please enter a commit number" << endl;
	string commitNum = getCommitNum();
	if (!isNumber(commitNum)) 
	{
		cout << "Please enter a valid commit number and try again." << endl; 
		return;
	}
	int commitNumber = stoi(commitNum);
	cout << "Commit # " << commitNumber << endl;

	if(commitNumber > commitHead->commitNumber || commitNumber < 1){
		if(commitNumber == -1) {
			cout << endl << "Returning to safety" << endl;
			return;
		}
		cout << "Please enter a valid commit number and try again." << endl; 
		return;
	} else {
		checkHead = commitHead;
		while(checkHead->commitNumber >= 1) {
			if(checkHead->commitNumber == commitNumber)
					break; // if version is correct, leave loop
			checkHead = checkHead->prev;
		} // end while

		// now we copy
		singlyNode * curr = checkHead->fileHead;
		while(curr != nullptr){
			string fileSource = ".miniGit/" + curr->fileName + curr->fileVersion;
			string fileDest = curr->fileName;
			file_copy(fileSource, fileDest);
			curr = curr->next;
		} // end while

		return;

	} // end if/else

} // end checkOut

void miniGit::commit(){
	
	if(commitHead->fileHead == nullptr) {
		cout << "Please add a file before committing" << endl;
		return;
	} // end if

	if(checkHead != commitHead) {
		cout << "You have checked out an old version" << endl;
		cout << "Check out the current version to push changes" << endl;
		cout << "Current Commit Number is: " << commitHead->commitNumber << endl;
		cout << "You have checked out version: " << checkHead->commitNumber << endl;
		return;
	} // end if

    singlyNode * curr = commitHead->fileHead;
    while(curr != nullptr){
        string fileName = curr->fileName + curr->fileVersion; //we will need to copy/save files in this format as well. (f1.txt01)
        string fileDest = ".miniGit/"+fileName;
        if(fileExist(fileDest)){
	    //cout << " file exists " << endl;
            if(is_equal(curr->fileName, fileDest)){ //file is unchanged
        		curr = curr->next;
                continue;
            } else { // if exists but has been changed
				//cout << "old file version: " << curr->fileVersion << endl;
                curr->fileVersion = to_string(stoi(curr->fileVersion) + 1); //increments fileVersion
				//cout << "new file version: " << curr->fileVersion << endl;
                fileName = curr->fileName + curr->fileVersion;
                fileDest = ".miniGit/"+fileName;
                file_copy(curr->fileName, fileDest);
            }// end inner if else
        } else { // the file doesn't exist
            file_copy(curr->fileName, fileDest);
        } // end else if
        curr = curr->next;
    } // end while

	//This section copies the doubly node and sets it to the new head
    singlyNode * temp = commitHead->fileHead; 
    doublyNode * head = new doublyNode;
	head->commitNumber = commitHead->commitNumber + 1;
    commitHead -> next = head;
    head->prev = commitHead;
    commitHead = head;
    commitHead->fileHead = nullptr;

	// this section (if & while) copy the corresponding singlylist	
	if(temp != nullptr){ // if the old commithead has a file
		curr = commitHead->fileHead; // new fileHead pointer
        singlyNode* newFile = new singlyNode();
        newFile->fileName = temp->fileName;
        newFile->fileVersion = temp->fileVersion;
		commitHead->fileHead = newFile;
		curr = newFile;
	} // end if

	temp = temp->next;
    while(temp != nullptr) {
        singlyNode* newFile = new singlyNode();
        newFile->fileName = temp->fileName;
        newFile->fileVersion = temp->fileVersion;
        newFile->next = nullptr;
        curr->next = newFile;
		temp = temp->next;
		curr = curr->next;
    } // end deep copy

	cout << "This is commit number: " <<  commitHead->commitNumber << endl;
	checkHead = commitHead;
} // end commit


