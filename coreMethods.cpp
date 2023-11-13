#include "coreMethods.h"

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