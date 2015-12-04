#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>

#include "Table.h"

using namespace std;

Table GLOBAL_TABLE;

int main (int argc, char **argv)
{
    ifstream iss(argv[1]);
    GLOBAL_TABLE.read(iss);
    GLOBAL_TABLE.compute();
    GLOBAL_TABLE.write(cout);
    
    

    return 0;
}



