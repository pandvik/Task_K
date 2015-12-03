#include "Table.h"


Size2d::Size2d(int sizex, int sizey)
{
    this->sizex = sizex;
    this->sizey = sizey;
}

Table::Table()
{
}
void Table::read(istream &inputStream)
{
    size = read_size(inputStream); 
    cout<<size.sizex<<size.sizey<<endl;
    // read lines
    vector<char> buff;
    int t;
    for (int lineNumber=0; lineNumber < size.sizey; lineNumber++)
    {
        for (int colNumber=0; colNumber < size.sizex; colNumber++)
        {
            for(t = inputStream.get();
                t != '\t' && t != '\n' && t != EOF;
                t = inputStream.get()) 
            { buff.push_back(t); }
            
            if ( (t == '\n' || t == EOF) && 
                (colNumber < (size.sizex-1) ) ) // not last column
            {
                // TODO: add row number
                throw (runtime_error("Some cells are missing on row"));
            }
            
            buff.push_back('\0');
            
            addCell(string(buff.data()), colNumber, lineNumber);
    
            buff.clear();
        }
        
        if (t != '\n' && t != EOF) // if there are else cells on this row
        {
            // TODO: add row number
            throw (runtime_error("There are some excess cells on row"));
        }   
        if (t == EOF && 
            lineNumber < (size.sizey - 1)) // not last row
        {
            throw (runtime_error("Some rows are missing"));
        }
    }
    if (t != EOF && inputStream.get() != EOF) // there are else rows 
    {
        throw (runtime_error("There are some excess rows"));
    }
}
bool Table::compute()
{
    return true;
}
void Table::write(ostream &outputStream)
{
}
Table::~Table()
{
}


Size2d Table::read_size(istream &inputStream)
{
    int buff_size = 256;
    char buff[buff_size];
    
    inputStream.getline(buff, buff_size);
    if (!inputStream.good())
    {
        throw (runtime_error("Error in input stream"));
    }
    
    std::regex pieces_regex("([0-9]+) ([0-9]+)\0");
    std::smatch pieces_match;
    if (std::regex_match(string(buff), pieces_match, pieces_regex)) 
    {
        std::string piece1 = pieces_match[1].str();
        std::string piece2 = pieces_match[2].str();
        
        return Size2d(stoi(piece2), stoi(piece1));
    }
    throw (runtime_error("Error while parsing first string"));
}


void Table::addCell(string data, int posX, int posY)
{
    cout<<"Cell "<<posX<<" "<<posY<<" : \'"<<data<<"\'"<<endl;
}

