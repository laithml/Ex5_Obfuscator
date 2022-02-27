//
// Created by Laith on 18/12/2021.
//

#include "CommentObfuscator.h"


void CommentObfuscator::obfuscate(string filename) {
    string Comments[]={"//check if even number","//check if prime number"
            ,"//check if odd number","//for loop on all elements in the array"
            ,"//this function calculate the sum of numbers in array"};

    string *fileString= parseFile(filename);
    int len= stoi(fileString[0].substr(2));

    int randLoc=0;
    int randNum=0;
    int j=0;
    randNum = rand() % 5;
    randLoc=rand() % len +1;
    int end=0;

    for(int i=1;i<len;i++){


        if(fileString[i].find("//")!=string::npos){
            fileString[i].replace(fileString[i].find("//"),fileString[i].length(),"");

        }
        string randCom = "\n" + Comments[randNum];
        if(i==randLoc) {
            fileString[randLoc] += randCom;
            j++;
            randLoc=rand()%(len-i)+i;
            randNum=rand() % 5;
        }
        if(fileString[i].find("}")!=string::npos)
            end=i;
    }
    if(end!=0){
        for(int i=end;i<len;i++){
            if(fileString[i].find("//")!=string::npos){
                fileString[i].replace(fileString[i].find("//"),fileString[i].length(),"");
            }
        }
    }

    len= FileLen(filename)+j;
    fileString[0]="//"+ to_string(len);

    writeToFile(fileString);




}