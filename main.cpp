#include <iostream>
using namespace std;


class folderSelect{
    string folderNames[10] = {"","","","","","","","","",""};


public:
     void openFolder(){
        for (int i = 0; i < 10; i++){
            cout << "Folder " << i << folderNames[i] << "\n";
        }
    }

    int createFolder(){
        return 0;
    }

    int deleteFolder(){
        return 0;
    }
};


class coreMethods{
public:
    string getString(string prompt){
        cout << prompt << endl;
        string answer;
        cin >> answer;
        return answer;
    }

    int getInt(string prompt){
        cout << prompt << endl;
        int answer;
        cin >> answer;
        return answer;
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

