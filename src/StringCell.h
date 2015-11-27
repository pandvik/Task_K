#ifndef STRINGcELL_H
#define STRINGcELL_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "Cell.h"

using namespace std;

class StringCell: public Cell
{
    string dataSource;
    string dataResult;
public:
    void StringCell(string src);

    
    virtual bool compute();
    
    virtual bool isString();
    /*
    * Get result after computing
    */     
    virtual string getResult();
    /*
    * Return source string if isString==true
    */ 
    virtual string getString();
    
    virtual ~StringCell();
};


#endif
