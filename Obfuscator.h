//
// Created by Laith on 17/12/2021.
//

#ifndef EX5_OBFUSCATOR_H
#define EX5_OBFUSCATOR_H
#include <iostream>
using namespace std;
class Obfuscator {
protected:
    int FileLen(string fileName);

public:
    const string OUT = "newCode.c";
    virtual void obfuscate(string fileName) = 0;
    string generateRandomVar();
    void writeToFile(string* codeArray);
    string* parseFile(string filename);

};




#endif //EX5_OBFUSCATOR_H
