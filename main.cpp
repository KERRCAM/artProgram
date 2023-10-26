#include <iostream>
using namespace std;


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
    bool exit = false;
    while (exit == false){
        string answer = CM.getString("What would you like to do? (enter number of action): \n (1)-Sign in \n (2)-Create account");
        if (answer == "1"){
            exit = true;
            cout << 0 << endl;
        }
        if (answer == "2"){
            exit = true;
            cout << 0 << endl;
        }
        else{
            cout << "please enter a valid number" << endl;
        }
    }



    return 0;
}

