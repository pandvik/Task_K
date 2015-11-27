#include "Table.h"

Table::Table()
{
    table = NULL;
}
bool Table::read(istream inputStream)
{
    string buff;
    char t;
    // skip spaces
    for(;(t=inputStream.get())==' ';) {;}
    // read number
    for(;(t=inputStream.get())!=' ';)
    {
        if (isdigit(t))
            buff.push_back(t);
        else // =='\n'
        {
            cout<<"Error while reading size of table."<<endl;
            return false;
        }
    }
    int sizeX = atoi(buff.c_str());
    buff.clear();
    
    // read number
    for(;(t=inputStream.get())!=' ' && t!='\n';)
    {
        if (isdigit(t))
            buff.push_back(t);
        else // =='\n'
        {
            cout<<"Error while reading size of table."<<endl;
            return false;
        }
    }
    int sizeY = atoi(buff.c_str());
    buff.clear();
    
    // Alloc memory for table 
    table = new Cell** [sizeY];
    for (int i=0; i < sizeY; i++)
    {
        table[i] = new Cell**[sizeX];
        for (int j=0; j < sizeX; j++)
            table[i][j] = NULL;
    }

    auto ln_table = table;
    auto getCell = [ln_table, sizeX, sizeY](int x, int y){
        if (x <= 0 
            || x > sizeX
            || y <= 0
            || y < sizeY )
            return (Cell*)NULL;
        return ln_table[y-1][x-1];
    };
    
    // read table    
    for(int row = 0; row < sizeY; row++)
    {
        char t;
        for(int col = 0; (t=inputStream.get())!='\n' && t != EOF && col < sizeX; )
        {
            // TODO: 
        }       
        
    }

    
}

bool Table::write(ostream outputStream)
{
 ;   
}
bool Table::compute()
{
    
}
Table::~Table()
{
}



