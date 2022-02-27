//
// Created by Laith on 17/12/2021.
//

//            for(int j=0;j<fileString[i].length();j++) {
//                if (fileString[i].at(j) == ',') {
//                    VarCount++;
//                    coma++;
//                }
//            }
#include "VarObfuscator.h"

void VarObfuscator::obfuscate(string filename){
    int len= FileLen(filename);
    string *fileString= parseFile(filename);
    string randName=generateRandomVar();
    string Var[15];
    int VarCount=0;
    int start=0;
    int end=0;
    for(int i=0;i<len;i++)
        if(fileString[i].find(" main")!=string::npos)
            start=i;

    while(start<len&&VarCount<10){
        if(fileString[start].find(" int ")!=string::npos){
            if(fileString[start].find("=")!=string::npos){
                for(int j=fileString[start].find(" int ")+5;j<fileString[start].length();j++) {
                    if(fileString[start].at(j)=='=') break;
                    Var[VarCount] += fileString[start].at(j);
                }
                VarCount++;
            }else {
                for(int j=fileString[start].find(" int ")+5;j<fileString[start].length();j++) {
                    if(fileString[start].at(j)==';') break;
                    Var[VarCount] += fileString[start].at(j);
                }
                VarCount++;
            }
        }

        start++;
    }

    if(VarCount!=0) {
        int randNum = rand() % VarCount;
        string temp = Var[randNum];

        for (int i = 1; i < len; i++) {
            if (fileString[i].find(temp) != string::npos) {
                fileString[i].replace(fileString[i].find(temp),temp.length() ,
                                      randName);
            }
        }
    }

    writeToFile(fileString);



};