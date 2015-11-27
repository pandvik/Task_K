#ifndef EXPRESSIONcELL_H
#define EXPRESSIONcELL_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "Cell.h"

using namespace std;

/*
 * Lambda function for getting cell from table
*/
typedef Cell* (*GetCellLambda)(int x, int y);

class ExpressionCell: public Cell
{
    // Flag, wich signify either Cell already computed or not
    bool computed;
    // Flag, wich setted if there is some error while computed this cell
    bool error;
    // Before computing, it contain input cell value, after - result of computing
    string data;
    int data_int;
    // Saved lambda function for getting cell from table
    GetCellLambda getCell;
    // Locking compute method for exclude recursive loop
    bool block;

public:
    ExpressionCell(string src, GetCellLambda getCell);

    virtual bool compute();
    bool _compute();
    
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

private:

};


#endif
