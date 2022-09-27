#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
#include <cctype>

class Convert
{
public:

    Convert(std::string const conv);
    Convert(Convert const & );
    ~Convert();
    Convert &operator=(Convert const &);

    const std::string getConv();
    int whichType(void);
    int interpreteValue();
    void found_char();
    void found_int();
    void found_float();
    void found_double();
    void found_error();
    int set_last();
    void print_cast();
    void setSpe();

private:

    std::string const   _conv;
    char                _char;
    int                 _int;
    float               _float;
    double              _double;
    const int _car;
    const int _integ;
    const int _flo;
    const int _db;
    const int _error;
    long double         _over;
    int                 _spe;
};