#ifndef CELL_H
#define CELL_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <exception>

using namespace std;

class Cell
{
public:
    virtual bool compute();
    
    /*
    * Test type of cell
    */
    virtual bool isEmpty();
    virtual bool isString();
    virtual bool isExpression();
    virtual bool isNumber();
    
    /*
    * Get result after computing
    */     
    virtual string getResult();
    /*
    * Return source string if isString==true
    */ 
    virtual string getString();
    /*
    * Return source number if isNumber==true
    */ 
    virtual int getNumber();
    virtual ~Cell();
    /*
    * Exception wich throw if getNumber or getString can't be executed 
    */ 
    class IncorrectGetTypeException: public exception
    {
        virtual const char* what() const throw();
    };
    
};


#endif
