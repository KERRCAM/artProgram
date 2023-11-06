#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
//make folders (up to 10), folders contain canvases (up to any number), everything in cavases done by shortcuts (aiming to be for quick prototyping, so speed over advanced features)
//folders - actually just txt file containing names of all related files
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

private:
    void readFolder(string folderName){ //may be easier to store file names in database along with folder too
        string fileNames[10] = {"","","","","","","","","",""};
        string folderContents;
        int fileNum;
        ifstream folderReader(folderName);
        while (getline (folderReader, folderContents)) {
            int count = 0;
            vector<string> v;
            stringstream ss(folderContents);
            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            for (size_t i = 0; i < v.size(); i++){
                count++;
                fileNames[count] = v[i];
            }
        }


        folderReader.close();
    }


public:
    void openFolder(){
        bool found = false;
        bool validFolder = false;
        for (int i = 0; i < 10; i++){
            cout << "Folder " << i << ":" << folderNames[i] << "\n";
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
                } else{
                    readFolder(selected);
                }
            }
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
            ofstream folder("filename.txt");
        }
    }

    void deleteFolder(){
        bool found = false;
        for (int i = 0; i < 10; i++){
            cout << "Folder " << i << ":" <<folderNames[i] << "\n";
            if (folderNames[i] != ""){
                found = true;
            }
        }
        if (found == false){
            cout << "No folders exist to be deleted" << endl;
        }else {
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
    }

};

int main() {
    coreMethods CM;
    folderSelect FS;
    bool exit = false;
    while (exit == false){
        string answer = CM.getString("What would you like to do? (enter number of action): \n (1)-Open folder \n (2)-Create new folder \n (3)-Delete folder \n (4)-Exit");
        if (answer == "1"){
            FS.openFolder();
        }
        if (answer == "2"){
            FS.createFolder();
        }
        if (answer == "3"){
            FS.deleteFolder();
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

