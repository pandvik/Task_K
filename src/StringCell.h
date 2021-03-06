#ifndef STRINGcELL_H
#define STRINGcELL_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "Cell.h"

using namespace std;

class StringCell: public Cell
{
    bool error;
    string data;
    bool computed;
public:
    StringCell(string src);

    virtual bool compute();
    
    virtual bool isString();
    /*
    * Get result after computing
    */     
    virtual string getResult();
    
    virtual ~StringCell();
};


#endif
