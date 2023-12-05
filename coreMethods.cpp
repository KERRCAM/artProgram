#include "coreMethods.h"

class coreMethods{
public:
    static string getString(string prompt){
        bool valid = false;
        string answer;
        while (!valid){
            cout << prompt << endl;
            cin >> answer;
            if (!answer.empty()){
                valid = true;
            }else{
                cout << "Cant accept empty string" << endl;
            }
        }
        return answer;
    }

    static int getInt(string prompt){
        cout << prompt << endl;
        int answer;
        cin >> answer;
        return answer;
    }

};