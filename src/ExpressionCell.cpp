#include "ExpressionCell.h"

bool isSign(char t)
{
    if (t == '+'
        || t == '-'
        || t == '*'
        || t == '\\')
        return true;
    return false;
}

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

bool isCellString(string str)
{
    if (str.size() == 2
        && isalpha(str[0])
        && isdigit(str[1]))
        return true;
    return false;
}

pair<int, int> parseCellCoordinate(string str)
{
    return pair<int, int>(str[0], str[1]);
}

bool ExpressionCell::compute()
{
    if (this->block)
        return false;
    this->block = true;
    bool ret = this->compute();
    this->block = false;
    return ret;
}
bool ExpressionCell::_compute()
{
    if (this->computed)
        return this->error ? false : true;

    if (data[0]!='=')
    {
        this->error = true;
        this->computed = true;
        this->data = "#parce_expr_error";
        return false;
    }
    
    enum {EQUAL='=', PLUS='+', MINUS='-', MULTIPLICATION='*', DIVISION='\\'} signState=EQUAL;
    int leftValue = 0;
    int rightArgBegin = 1;
    for (unsigned int i=1; i<data.size()+1; i++)
    {
        if ( (i == data.size()-1)
            ||  isSign(data[i]) )
        {
            int rightValue = 0;
            string rightArg = data.substr(rightArgBegin, i-1);
            if (isNumberString(rightArg))
                rightValue = atoi(rightArg.c_str());
            else if (isCellString(rightArg))
            {
                pair<int, int> cellCoord = parseCellCoordinate(rightArg);
                Cell *cell = getCell(cellCoord.first, cellCoord.second);
                // if cell not found or cell can't be computed => error
                if (cell == NULL || !cell->compute() || !cell->isNumber())
                {
                    this->error = true;
                    this->computed = true;
                    this->data = "#incorrect_cell_"+rightArg;
                    return false;
                }
                rightValue = cell->getNumber();
            }
            // Compute operation
            switch (signState)
            {
            case EQUAL: leftValue = rightValue; break;
            case PLUS: leftValue += rightValue; break;
            case MINUS: leftValue -= rightValue; break;
            case MULTIPLICATION: leftValue *= rightValue; break;
            case DIVISION:
                if (rightValue == 0)
                {
                    this->error = true;
                    this->computed = true;
                    this->data = "#division_by_zero";
                    return false;
                }
                leftValue /= rightValue;   
                break;
            }
        }   
        if ( i == data.size()-1 )
            break;
        // set next sing       
        if (data[i] == '+')
            signState = PLUS;
        if (data[i] == '-')
            signState = MINUS;
        if (data[i] == '*')
            signState = MULTIPLICATION;
        if (data[i] == '/')
            signState = DIVISION;
    }
    this->error = false;
    this->computed = true;
    this->data = std::to_string(leftValue);
    this->data_int = leftValue;
    return true;   
}

ExpressionCell::ExpressionCell(string str, GetCellLambda getCell)
{
    this->error = false;
    this->computed = false;
    this->data = str;
    this->getCell = getCell;
}

bool ExpressionCell::isString()
{
    return false;
}
bool ExpressionCell::isNumber()
{
    this->compute();
    return this->error ? false : true;
}

string ExpressionCell::getResult()
{
    this->compute();
    return this->data;
}

int ExpressionCell::getNumber()
{
    this->compute();
    return this->data_int;
}

ExpressionCell::~ExpressionCell()
{
}













