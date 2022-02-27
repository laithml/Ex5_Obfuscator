//
// Created by Laith on 17/12/2021.
//
#include "Obfuscator.h"
#include <iostream>
#include <fstream>
#include <string>


int Obfuscator::FileLen(string fileName)  {
    ifstream file;
    file.open(fileName);
    string line;

    int fileLength=0;
    while(getline(file,line)) fileLength++;
    file.close();
    return fileLength;
}


string Obfuscator:: generateRandomVar(){
    int random[4];
    int n= rand()%10+3;
    string randStr;
    int randNum;
    for(int i=0;i<n;i++){
        random[0]=rand()%9+48; //numbers
        random[1]=95;//underScore
        random[2]=rand()%25+65;//small letters
        random[3]=rand()%25+97;//big letters
        if(i==0){
            randNum=rand()%3+1;//choose from random array from 1 to 3 (underScore and letters only)
            randStr+=random[randNum];
        }
        randNum=rand()%4;
        randStr+=random[randNum];
    }
    return randStr;
}

string* Obfuscator:: parseFile(string filename){
    ifstream file;
    file.open(filename);
    string line;

    int fileLength=0;
    while(getline(file,line)) fileLength++;


    string *All=new string[fileLength+1] ;

    file.close();
    file.open(filename);
    int i=1;
    All[0]="//"+ to_string(fileLength);
    while(getline(file,line)){
        All[i]=line;
        i++;
    }
    file.close();
    return All;
}

void Obfuscator:: writeToFile(string* codeArray){
    ofstream file;
    int len=stoi(codeArray[0].substr(2))+1;
//    string str="/Users/laith/CLionProjects/Ex5/"+OUT;
    file.open(OUT);
    for(int i=1;i<len;i++)
        file << codeArray[i] <<endl;


    file.close();

}