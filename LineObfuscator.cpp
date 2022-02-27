//
// Created by Laith on 17/12/2021.
//

#include "LineObfuscator.h"
#include "Obfuscator.h"
#include <string>


void LineObfuscator::obfuscate(string fileName) {

    string *FileString = Obfuscator::parseFile(fileName);
    int N = FileLen(fileName);
    int rand1 = rand() % 9999;
    int rand2 = rand() % 9999;
    int end=0,main=0;
    FileString[0]="//"+ to_string(N);

    string randVar = Obfuscator::generateRandomVar();
    string eq = "\n\t"+randVar + " = " + to_string(rand1) + " + " + to_string(rand2) + ";";

    for (int i = 1; i < N ; i++) {
        if (FileString[i].find("main()")!=string::npos) {
            FileString[0]="//"+ to_string(N+2);
            FileString[i+1] += "\n\tint " + randVar + ";";
            main=i;
        }
        if(FileString[i].find("}")!=string::npos)
            end=i;
    }

    if(main!=0) {
        int newLine = rand() % (main - end) +main ;
        FileString[newLine] += eq;
    }
    writeToFile(FileString);

}


