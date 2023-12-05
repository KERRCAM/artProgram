#include "folderMethods.h"
#include "coreMethods.h"

void folderMethods::readFolder(const string &folderName) { //may be easier to store file names in database along with folder too
    string fileNames[10] = {"", "", "", "", "", "", "", "", "", ""};
    string folderContents;
    ifstream folderReader(folderName);
    while (getline(folderReader, folderContents)) {
        int count = 0;
        vector<string> v;
        stringstream ss(folderContents);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        for (size_t i = 0; i < v.size(); i++) {
            count++;
            fileNames[count] = v[i];
        }
    }
    folderReader.close();
}

void folderMethods::openFolder() { //need to have sub menu for adding and deleting files within the folder
    bool found = false;
    bool validFolder = false;
    for (int i = 0; i < 10; i++) {
        cout << "Folder " << i << ":" << folderNames[i] << "\n";
        if (!folderNames[i].empty()) {
            found = true;
        }
    }
    if (!found) {
        cout << "No folder exist yet to be opened. Please create a folder." << endl;
    } else {
        while (!validFolder) {
            string selected = getString("Enter name of folder you want to be opened: ");
            for (int i = 0; i < 10; i++) {
                if (selected == folderNames[i]) {
                    validFolder = true;
                    readFolder(selected);
                }
            }
            if (!validFolder) {
                cout << "Folder name entered incorrectly" << endl;
            } else {
                readFolder(selected);
            }
        }
    }
}

void folderMethods::createFolder() {
    bool found = false;
    int space = -1; //gets index of first empty spot if there is one
    string newFolder;
    for (int i = 0; i < 10; i++) {
        if (folderNames[i].empty() && space == -1) {
            found = true;
            space = i;
        }
    }
    if (!found) {
        cout << "No space for new folder. Please delete existing folder to make room for new folder." << endl;
    } else {
        newFolder = getString("What would you like to call new folder?: ");
        folderNames[space] = newFolder;
        ofstream folder("filename.txt");
    }
}

void folderMethods::deleteFolder() {
    bool found = false;
    for (int i = 0; i < 10; i++) {
        cout << "Folder " << i << ":" << folderNames[i] << "\n";
        if (!folderNames[i].empty()) {
            found = true;
        }
    }
    if (!found) {
        cout << "No folders exist to be deleted" << endl;
    } else {
        for (int i = 0; i < 10; i++) {
            cout << "Folder " << i << ":" << folderNames[i] << "\n";
        }
        bool validFolder = false;
        while (!validFolder) {
            string folder = getString(
                    "Please enter name of Folder to be deleted (Note deleting a folder just deletes it off the program folder list, not your system, no data is lost)");
            for (int i = 0; i < 10; i++) {
                if (folder == folderNames[i]) {
                    validFolder = true;
                }
            }
        }
        if (validFolder == true) {
            bool confirmed = false;
            string confirmation = getString("Please type CONFIRM to delete the folder or CANCEL to stop");
            if (confirmation == "CONFIRM") {
                cout << 0 << endl; // put in actual deletion method call once made
            } else {
                cout << "Folder deletion canceled" << endl;
            }
        }
    }
}