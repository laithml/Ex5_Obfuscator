#include <iostream>

#include "Obfuscator.h"
#include "VarObfuscator.h"
#include "LineObfuscator.h"
#include "CommentObfuscator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
int main() {
    srand (time(NULL));
    Obfuscator* obfs[3];
    obfs[0] = new VarObfuscator();
    obfs[1] = new CommentObfuscator();
    obfs[2] = new LineObfuscator();

    obfs[0]->obfuscate("txt.txt");
    for(int i = 1; i < 3; i++)
        obfs[i]->obfuscate(obfs[i-1]->OUT);

    for(int i=0;i<3;i++)
        delete obfs[i];


    return 0;
}
