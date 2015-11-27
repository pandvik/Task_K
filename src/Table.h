#ifndef TABLE_H
#define TABLE_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

#include "Cell.h"
#include "EmptyCell.h"
#include "ExpressionCell.h"
#include "StringCell.h"
#include "NumberCell.h"

class Table
{
    Cell *** table;   
public:
    Table();
    bool read(istream inputStream);
    bool write(ostream outputStream);
    bool compute();
    ~Table();
};
#endif
