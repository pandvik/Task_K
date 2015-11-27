#ifndef NumberCell_H
#define NumberCell_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "Cell.h"

using namespace std;

class NumberCell: public Cell
{
    bool computed;
    bool error;
    string data;
    int data_int;
public:
    NumberCell(string str);

    virtual bool compute();
    
    virtual bool isNumber();
    /*
    * Get result after computing
    */     
    virtual string getResult();
    /*
    * Return source number if isNumber==true
    */ 
    virtual int getNumber();
    
    virtual ~NumberCell();
};


#endif
