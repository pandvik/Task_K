#include "StringCell.h"


bool StringCell::compute()
{
    // If it was not computed
    if (this->computed)
        return this->error ? false : true;
    
    // If the string begin with '
    if (this->data[0] == '\'')
    {
        // Delete first simbol
        this->data = this->data.substr(1);
        this->computed = true;            
        return true;
    }
    else
    {
        this->error = true;
        this->data = "#incorrectCell";
        return false;
    }
}

StringCell::StringCell(string str)
{
    this->computed = false;
    this->error = false;
    this->data = str;
}

bool StringCell::isString()
{
    // try to compute
    this->compute();
    
    // if there is error then it is not string
    return this->error ? false : true;
}

string StringCell::getResult()
{
    // try to compute
    this->compute();
    
    return this->data;
}

StringCell::~StringCell()
{
}
