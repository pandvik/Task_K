#include "Cell.h"

bool Cell::isEmpty()
{
    return false;
}
bool Cell::isString()
{
    return false;
}
bool Cell::isExpression()
{
    return false;
}
bool Cell::isNumber()
{
    return false;
}

string Cell::getString()
{
    return "";
}
int Cell::getNumber()
{
    return 0;
}

const char* Cell::IncorrectGetTypeException::what() const throw()
{
    const char *errorMsg = "This method can't be executed. There is not data of this type.";
    return errorMsg;
}

