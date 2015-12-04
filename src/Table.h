#ifndef tABLE_H
#define tABLE_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <stdexcept>
#include <regex>
#include <fstream>
#include <vector>

#include "Cell.h"
using namespace std;

struct Size2d
{   
    int sizex;
    int sizey;   
    Size2d(int sizex=0, int sizey=0);
};

class Cell;

class Table
{
    Size2d size;
    
    Cell ***table;
public:
    Table();
    void read(istream &inputStream);
    bool compute();
    void write(ostream &outputStream);
    ~Table();
    Cell* getCell(int x, int y);
private:
    Size2d read_size(istream &inputStream);
    void addCell(string data, int posX, int posY);
};


#endif
