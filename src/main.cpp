#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>

#include "Table.h"

using namespace std;

int main (int argc, char **argv)
{
    ifstream iss(argv[1]);
    Table tt;
    tt.read(iss);

    return 0;
}



