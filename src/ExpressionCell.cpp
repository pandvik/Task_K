#include "ExpressionCell.h"


bool ExpressionCell::compute()
{
    return true;   
}

ExpressionCell::ExpressionCell(string str)
{
    this->error = false;
    this->computed = false;
    this->data = str;
}

bool ExpressionCell::isString()
{
    return false;
}
bool ExpressionCell::isNumber()
{
    return true;
}

string ExpressionCell::getResult()
{
    return "";
}

int ExpressionCell::getNumber()
{
    return 0;
}

ExpressionCell::~ExpressionCell()
{
}
