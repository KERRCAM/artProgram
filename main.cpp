#include <iostream>
#include <fstream>
using namespace std;
//make folders (up to 10), folders contain canvases (up to any number), everything in cavases done by shortcuts (aiming to be for quick prototyping, so speed over advanced features)

class coreMethods{

public:
    string getString(string prompt){
        bool valid = false;
        string answer;
        while (valid == false){
            cout << prompt << endl;
            cin >> answer;
            if (answer != ""){
                valid = true;
            }else{
                cout << "Cant accept empty string" << endl;
            }
        }
        return answer;
    }

    int getInt(string prompt){
        cout << prompt << endl;
        int answer;
        cin >> answer;
        return answer;
    }

};

class folderSelect{
    coreMethods CM;
    string folderNames[10] = {"","","","","","","","","",""};

public:
    void openFolder(){
        bool found = false;
        bool validFolder = false;
        for (int i = 0; i < 10; i++){
            cout << "Folder " << i << ":" <<folderNames[i] << "\n";
            if (folderNames[i] != ""){
                found = true;
            }
        }

        if (found == false){
            cout << "No folder exist yet to be opened. Please create a folder." << endl;
        }else{
            while (validFolder == false) {
                string selected = CM.getString("Enter name of folder you want to be opened: ");
                for (int i = 0; i < 10; i++) {
                    if (selected == folderNames[i]) {
                        validFolder = true;
                    }
                }
                if (validFolder == false){
                    cout << "Folder name entered incorrectly" << endl;
                }
            }
            //method call with name argument to open folder
        }
    }

    void createFolder(){
        bool found = false;
        int space; //gets index of empty spot if there is one
        string newFolder;
        for (int i = 0; i < 10; i++){
            if (folderNames[i] != ""){
                newFolder = CM.getString("What would you like to call new folder?: ");
                found = true;
                space = i;
            }
        }
        if (found == false){
            cout << "No space for new folder. Please delete existing folder to make room for new folder." << endl;
        } else{
            folderNames[space] = newFolder;
            // call method for actually making new folder
        }
    }

    void deleteFolder(){
        for (int i = 0; i < 10; i++){
            cout << "Folder " << i << ":" << folderNames[i] << "\n";
        }
        bool validFolder = false;
        while (validFolder == false) {
            string folder = CM.getString("Please enter name of Folder to be deleted (Note deleting a folder just deletes it off the program folder list, not your system, no data is lost)");
            for (int i = 0; i < 10; i++) {
                if (folder == folderNames[i]) {
                    validFolder = true;
                }
            }
        }
        if (validFolder = true){
            bool confirmed = false;
            string confirmation = CM.getString("Please type CONFIRM to delete the folder or CANCEL to stop");
            if (confirmation == "CONFIRM"){
                cout << 0 << endl; // put in actual deletion method call once made
            }else{
                cout << "Folder deletion canceled" << endl;
            }
        }
    }

};

int main() {
    coreMethods CM;
    folderSelect FS;
    bool exit = false;
    while (exit == false){
        string answer = CM.getString("What would you like to do? (enter number of action): \n (1)-Open folder \n (2)-Create new folder \n (3)-Delete folder");
        if (answer == "1"){
            exit = true;
            FS.openFolder();
        }
        if (answer == "2"){
            exit = true;
            FS.createFolder();
        }
        if (answer == "3"){
            exit = true;
            FS.deleteFolder();
        }
        else{
            cout << "please enter a valid number" << endl;
        }
    }

    return 0;
}

