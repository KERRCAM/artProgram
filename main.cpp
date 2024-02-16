#include <iostream>
#include "coreMethods.h"
#include "folderMethods.h"
using namespace std;

//make folders (up to 10), folders contain canvases (up to any number), everything in canvases done by shortcuts (aiming to be for quick prototyping, so speed over advanced features)
/*
Database
folders(folderID, folderName)
files(folderID, fileID, fileName)
--do saved colour storage in text file
*/

int main() {
    bool exit = false;
    while (!exit){
        int answer = getInt("What would you like to do? (enter number of action): \n (1)-Open folder \n (2)-Create new folder \n (3)-Delete folder \n (4)-Exit");
        switch (answer){
            case 1:
                openFolder();
                break;
            case 2:
                createFolder();
                break;
            case 3:
                deleteFolder();
                break;
            case 4:
                exit = true;
                break;
        }
        cout << "Please enter a valid number" << endl;
    }

    return 0;
}

