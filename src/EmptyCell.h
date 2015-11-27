#ifndef EMPTYcELL_H
#define EMPTYcELL_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "Cell.h"

using namespace std;

class EmptyCell: public Cell
{
public:
    EmptyCell();

    virtual bool compute();
    
    virtual bool isEmpty();
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
    
    virtual ~EmptyCell();
};


#endif
