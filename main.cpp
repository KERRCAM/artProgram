#include <iostream>
#include "coreMethods.h"
#include "paintMethods.h"
#include "folderSelect.h"
using namespace std;

//make folders (up to 10), folders contain canvases (up to any number), everything in cavases done by shortcuts (aiming to be for quick prototyping, so speed over advanced features)
/*
Database
folders(folderID, folderName)
files(folderID, fileID, fileName)
--do saved colour storage in text file
*/

int main() {
    bool exit = false;
    while (exit == false){
        string answer = getString("What would you like to do? (enter number of action): \n (1)-Open folder \n (2)-Create new folder \n (3)-Delete folder \n (4)-Exit");
        if (answer == "1"){
            openFolder();
        }
        if (answer == "2"){
            createFolder();
        }
        if (answer == "3"){
            deleteFolder();
        }
        if (answer == "4"){
            exit = true;
        }
        else{
            cout << "please enter a valid number" << endl;
        }
    }

    return 0;
}

