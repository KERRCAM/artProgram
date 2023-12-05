#ifndef ARTPROGRAM_FOLDERMETHODS_H
#define ARTPROGRAM_FOLDERMETHODS_H
#include "coreMethods.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class folderMethods {

private:
    string folderNames[10] = {"","","","","","","","","",""};
    static void readFolder(const string& folderName);
public:
    void openFolder();

    void createFolder();

    void deleteFolder();
};


#endif //ARTPROGRAM_FOLDERMETHODS_H
