#ifndef MOD
#define MOD
#include "textfilereader.hpp"

std::string TextFileReader::get()
{
    std::string tmp = str;
    if (getline(f, str))
    {
        return tmp;
    }
    else
    {
        flag = false;
        return tmp;
    }
}

bool TextFileReader::hasNext() const
{
    return flag;    
}

#endif