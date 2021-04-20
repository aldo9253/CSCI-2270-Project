// Alex Doner & E.O Rafelson
// CSCSI 2270 Project
// miniGit.cpp
//


#include "miniGit.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

miniGit::miniGit(){
  //fs::remove_all(".miniGit");
  //fs::create_directory(".miniGit");
} // end constructor

miniGit::~miniGit(){
  //fs::remove_all(".miniGit");
} // end destructor

void miniGit:: init(){
  commitHead = new doublyNode;
  commitHead->next = 0;
  commitHead->prev = 0;
  commitHead->fileHead = 0;
  //commitHead->fileVersion = 0;
  //
}

//some helper functions
string getFileName(){
    cout << "Please type the name of the file you wish to add" << endl;
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (cin, name);
    return name;
} // end getFileName

bool fileExist(string fileName){
    ifstream ifile;
    ifile.open(fileName);
    if(ifile)
        return true;
    else
        return false;
} // end fileExist

void miniGit::addFile(){
    if (commitHead == 0) {
      cout << "miniGit not initialized" << endl;
    }
    else {
        string fileName = getFileName();
        singlyNode * curr = commitHead->fileHead;
        while (curr!=0)
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
        } else {
            cout << "File doesn't exist" << endl;
        }


    return;
    }

} // end addfile

void miniGit::removeFile(){
  string fileName = getFileName();
  if (commitHead == 0) {
    cout << "minigit not initialized" << endl;
  }
  else
  {
    singlyNode* curr = commitHead->fileHead;
    singlyNode* prev = 0;
    while (curr != 0)
    {
      if (curr->fileName == fileName) {
        if (prev !=0) {
          prev->next = curr->next;
          delete curr;
          return;
        }
        else {
          commitHead->fileHead = curr->next;
          delete curr;
          return;
        }
      }
      prev = curr;
      curr = curr->next;
    }
    cout << "File does not exist" << endl;
    return;
  }
} // end removefile

void file_copy(string f1name, string f2name) {
  // this function still needs to be tested !!!
  ifstream f1(f1name);
  ofstream f2(f2name);
  char c1, c2;          //niether flad nor c2 is used here, clean this up later
  bool flag = true;

  if (!f1.is_open()) {
    cout << "input file not found" << endl;
    return;
  }
  if(!f2.is_open()) {
    cout << "output file can't be opened" << endl;
    return;
  }

  while(1)
  {
    c1 = f1.get();
    if(c1 == EOF)
    {
      break;
      f2 << c1;
    }
    f1.close();
    f2.close();
  }
  
} // end file_copyShell

bool is_equal(string f1name, string f2name)
{ 
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
    
} // end checkOut

void miniGit::commit(){
    //TEST ME
    singlyNode * curr = commitHead->fileHead;
    while(curr != nullptr){
        string fileName = curr->fileName + curr->fileVersion; //we will need to copy/save files in this format as well. (f1.txt01)
        string fileDest = ".miniGit/"+fileName;
        if(fileExist(fileName)){
            if(is_equal(curr->fileName, fileDest)){ //file is unchanged
                break; // make sure this doesn't break too far
            } else {
                //curr->fileVersion ++; //increment file version
                curr->fileVersion = to_string(stoi(curr->fileVersion) + 1);
                fileName = curr->fileName + curr->fileVersion;
                fileDest = ".miniGit/"+fileName;
                //curr->filename = filename; // see comments below.
                file_copy(curr->fileName, fileDest);
                // is the copy before or after the file_copy?
                // should we update curr->fileName to include the ver #?
            }
        } else {
            file_copy(curr->fileName, fileDest);
        }
        curr = curr->next;
    } // end while

    // traverse singly list
    // for all files, check wether the fileVersion exists
        // if exists
            // check for changes against correct fileVersion
            // If unchanged do nothing
            // If changed copy the file from curr directory to git directory 
                //and update version # (named appropriately)
        // if not exists 
            // copy file from current directory into .minigit directory
            // filename should include the fileVersion correctly
    // Create a new doubly linked list node 
        // do a deep copy of the SLL from the prev node
        // increment commit #


} // end checkOut
// we should make a subroutine for the deep copy
// fileName = f1.txt -> .miniGit/f1.txt01 (.version)