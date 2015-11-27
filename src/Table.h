#ifndef TABLE_H
#define TABLE_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

class Table
{
public:
    void Table();
    bool read(istream inputStream);
    bool write(ostream outputStream);
    bool compute();
    ~Table();
};
#endif
