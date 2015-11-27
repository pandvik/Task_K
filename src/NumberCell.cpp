#include "NumberCell.h"


bool isNumberString(string str)
{
    if (str.size() == 0)
        return false;
    for(unsigned int i=0; i<str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool NumberCell::compute()
{
    if (this->computed)
        return this->error ? false : true;
    
    if (isNumberString(this->data))
    {
        this->computed = true;
        this->data_int = atoi(this->data.c_str());
        return true;
    }
    else
    {
        this->computed = true;
        this->error = true;
        this->data = "#no_int";
        return false;
    }
}

NumberCell::NumberCell(string str)
{
    this->computed = false;
    this->error = false;
    this->data = str;
    this->data_int = 0;
}

bool NumberCell::isNumber()
{
    this->compute();
    return this->error ? false : true ;
}

string NumberCell::getResult()
{
    this->compute();
    return this->data;
}
int NumberCell::getNumber()
{
    this->compute();
    return this->data_int;
}

NumberCell::~NumberCell()
{
}
