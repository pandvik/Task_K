#ifndef EXPRESSIONcELL_H
#define EXPRESSIONcELL_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "Cell.h"

using namespace std;

class ExpressionCell: public Cell
{
    bool computed;
    bool error;
    string data;
public:
    ExpressionCell(string src);

    virtual bool compute();
    
    virtual bool isString();
    virtual bool isNumber();
    /*
    * Get result after computing
    */     
    virtual string getResult();
    /*
    * Return source number if isNumber==true
    */ 
    virtual int getNumber();
    
    virtual ~ExpressionCell();
};


#endif
