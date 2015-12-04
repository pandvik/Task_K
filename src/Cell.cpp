#include "Cell.h"

Cell::Cell(string data)
{
    sourceData = data;
    state = UNKNOWN;
}

void Cell::compute()
{
    if (state != UNKNOWN)
        return;

    if (sourceData.empty())
    {
        resultData = sourceData;
        state = EMPTY;
    }
    else if (sourceData[0] == '\'')
    {
        resultData = sourceData.substr(1);
        state = STRING;
    }
    else if (sourceData[0] == '=')
    {
        computeExpression();   
    }
    else if (isNumberString(sourceData))
    {
        resultData = sourceData;
        intData = stoi(sourceData);
        state = NUMBER;
    }
    else
    {
        resultData = "#Incorrect cell format";
        state = ERROR;
    }
}
Cell::CellType Cell::getType()
{
    if (state == UNKNOWN)
        compute();
    return state;
}
int Cell::getInt()
{
    if (state == UNKNOWN)
        compute();
    if (state == NUMBER)
        return intData;
    throw (runtime_error ("The cell is not number"));   
}
string Cell::getString()
{
    if (state == UNKNOWN)
        compute();
    return resultData;
}


void Cell::computeExpression()
{
    if (computing)
    {
        state = ERROR;
        resultData = "#loop";
        return;
    }
    computing = true;
    _computeExpression();
    computing = false;
}
void Cell::_computeExpression()
{
    enum {EQUAL='=', PLUS='+', MINUS='-', MULTIPLICATION='*', DIVISION='/'} signState=EQUAL;
    int leftValue = 0;
    int rightArgBegin = 1;
    for (unsigned int i=1; i<sourceData.size()+1; i++)
    {
        if ( (i == sourceData.size()-1)
            ||  isSign(sourceData[i]) )
        {
            int rightValue = 0;
            string rightArg = sourceData.substr(rightArgBegin, (i == sourceData.size()-1 ? i : i-1) - rightArgBegin + 1);
            if (isNumberString(rightArg))
                rightValue = stoi(rightArg);
            else if (isCellString(rightArg))
            {
                pair<int, int> cellCoord = parseCellCoordinate(rightArg);
                Cell *cell = getCell(cellCoord.first, cellCoord.second);
                // if cell not found or cell can't be computed => error
                if (cell == NULL || cell->getType() != Cell::NUMBER)
                {
                    if (state != ERROR)
                    {
                        state = ERROR;
                        resultData = "#incorrect_cell_"+rightArg+"_";
                    }
                    return;
                }
                    
                rightValue = cell->getInt();
            }
            else
            {
                state = ERROR;
                resultData = "#incorrect expression";
                return;
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
                    state = ERROR;
                    resultData = "#division_by_zero";
                    return;
                }
                leftValue /= rightValue;   
                break;
            }
            rightArgBegin = i + 1;
        }   
        if ( i == sourceData.size()-1 )
            break;
        // set next sing       
        if (sourceData[i] == '+')
            signState = PLUS;
        if (sourceData[i] == '-')
            signState = MINUS;
        if (sourceData[i] == '*')
            signState = MULTIPLICATION;
        if (sourceData[i] == '/')
            signState = DIVISION;
    }

    resultData = std::to_string(leftValue);
    intData = leftValue;
    state = NUMBER;   
}

Cell* Cell::getCell(int x, int y)
{
    return GLOBAL_TABLE.getCell(x, y);
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

bool isSign(char t)
{
    if (t == '+'
        || t == '-'
        || t == '*'
        || t == '/')
        return true;
    return false;
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
    int x = str[0]-'A';
    int y = str[1]-'0';
    return pair<int, int>(x, y-1);
}



