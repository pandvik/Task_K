#include "EmptyCell.h"


bool EmptyCell::compute()
{
    return true;   
}

EmptyCell::EmptyCell()
{
}

bool EmptyCell::isEmpty()
{
    return true;
}

bool EmptyCell::isString()
{
    return true;
}

bool EmptyCell::isNumber()
{
    return true;
}

string EmptyCell::getResult()
{
    return "";
}
int EmptyCell::getNumber()
{
    return 0;
}

EmptyCell::~EmptyCell()
{
}
