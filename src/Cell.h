#ifndef cELL_H
#define cELL_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "Table.h"
using namespace std;

class Table;
extern Table GLOBAL_TABLE;

class Cell
{
public:
    enum CellType { EMPTY, STRING, NUMBER, EXPRESSION, ERROR, UNKNOWN };
    
    Cell(string data);
    void compute();
    CellType getType();
    int getInt();
    string getString();

private:
    void computeExpression();
    void _computeExpression();
    Cell* getCell(int x, int y);
    
    CellType state;
    string sourceData;
    string resultData;
    int intData;
    bool computing;
};


bool isNumberString(string str);
bool isSign(char t);
bool isCellString(string str);
pair<int, int> parseCellCoordinate(string str);

#endif
