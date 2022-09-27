#include "Convert.hpp"


Convert::Convert(std::string const conv) : _conv(conv), _char('0'), _int(0), _float(0), _double(0), _car(0), _integ(1), _flo(2), _db(3), _error(-1), _over(0), _spe(0)
{
    std::cout << "default constructor called" << std::endl;
    return ;
}

Convert::Convert(Convert const & conv) : _conv(""), _char('0'), _int(0), _float(0), _double(0), _car(0), _integ(1), _flo(2), _db(3), _error(-1), _over(0), _spe(0)
{
    if (this != &conv)
        *this = conv;
    std::cout << "copy constructor called" << std::endl;
    return ;
}

Convert::~Convert()
{
    std::cout << "default destructor called" << std::endl;
    return ;
}

const std::string Convert::getConv()
{
    return (_conv);
}

Convert &Convert::operator=(Convert const & conv)
{
    if (this == &conv)
        return (*this);
    //nothing can copy
    return (*this);
}

int Convert::interpreteValue()
{
    if (whichType() == _error)
        return (std::cout << "unaccepted argument" << std::endl, -1);
    else if (whichType() == _car)
        return (_char = _conv[0], 0);
    else if (whichType() == _integ)
        return (_over = strtold(_conv.c_str(), NULL), 1);
    else if (whichType() == _flo)
        return (_over = strtold(_conv.c_str(), NULL), 2);
    else
        return (_over = strtold(_conv.c_str(), NULL), 3);
}

void Convert::found_char()
{
    std::cout << "char: '" << _char << "'" << std::endl;
    _int = static_cast<int>(_char);
    std::cout << "int: " << _int << std::endl;
    _float = static_cast<float>(_char);
    std::cout << "float: "<< _float << "f" << std::endl;
    _double = static_cast<double>(_char);
    std::cout << "double: " << _double << std::endl;
    return ;
}

void Convert::found_int()
{
    _int = static_cast<int>(_over);
    if ( _int >= 33 && 126 >= _int)
    {
        _char = static_cast<char>(_int);
        std::cout << "char: '" << _char << "'" << std::endl;
    }
    else
        std::cout << "char: Non dispayable"<< std::endl;
    
    if (_over < std::numeric_limits<int>::min() || _over > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
    {
        _int = static_cast<int>(_over);
        std::cout << "int: " << _int << std::endl;
    }
    if (_over == -std::numeric_limits<float>::infinity() || _over > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        _float = static_cast<float>(_over);
        std::cout << std::fixed << std::setprecision(1) << "float: "<< _float << "f" << std::endl;
    }
    if (_over == -std::numeric_limits<double>::infinity() || _over > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
    {
        _double = static_cast<double>(_over);
        std::cout << std::fixed << std::setprecision(1) << "double: " << _double << std::endl;
    }
    return ;
}

void Convert::found_float()
{
    _float = static_cast<float>(_over);
    if ( _float >= 33 && 126 >= _float)
    {
        if (int(_float) == _float)
        {
            _char = static_cast<char>(_float);
            std::cout << "char: '" << _char << "'" << std::endl;
        }
        else
            std::cout << "char: Non dispayable"<< std::endl;
    }
    else
        std::cout << "char: Non dispayable"<< std::endl;
    
    if (_over < std::numeric_limits<int>::min() || _over > std::numeric_limits<int>::max() || _spe == 1)
        std::cout << "int: impossible" << std::endl;
    else
    {
        _int = static_cast<int>(_over);
        std::cout << "int: " << _int << std::endl;
    }
    if (_over == -std::numeric_limits<float>::infinity() || _over > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        _float = static_cast<float>(_over);
        std::cout << std::fixed << std::setprecision(1) << "float: "<< _float << "f" << std::endl;
    }
    if (_over == -std::numeric_limits<double>::infinity() || _over > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
    {
        _double = static_cast<double>(_over);
        std::cout << std::fixed << std::setprecision(1) << "double: " << _double << std::endl;
    }
    return ;
}

void Convert::found_double()
{
    _double = static_cast<float>(_over);
    if ( _double >= 33 && 126 >= _double)
    {
        if (int(_double) == _double)
        {
            _char = static_cast<char>(_double);
            std::cout << "char: '" << _char << "'" << std::endl;
        }
        else
            std::cout << "char: Non dispayable"<< std::endl;
    }
    else
        std::cout << "char: Non dispayable"<< std::endl;
    
    if (_over < std::numeric_limits<int>::min() || _over > std::numeric_limits<int>::max() || _spe == 1)
        std::cout << "int: impossible" << std::endl;
    else
    {
        _int = static_cast<int>(_over);
        std::cout << "int: " << _int << std::endl;
    }
    if (_over == -std::numeric_limits<float>::infinity() || _over > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        _float = static_cast<float>(_over);
        std::cout << std::fixed << std::setprecision(1) << "float: "<< _float << "f" << std::endl;
    }
    if (_over == -std::numeric_limits<double>::infinity() || _over > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
    {
        _double = static_cast<double>(_over);
        std::cout << std::fixed << std::setprecision(1) << "double: " << _double << std::endl;
    }
    return ;
}

void Convert::found_error()
{
    return ;
}
int Convert::set_last()
{
    int res = interpreteValue();
    if (res == -1)
        found_error();
    else if (res == 0)
        found_char();
    else if (res == 1)
        found_int();
    else if (res == 2)
        found_float();
    else
        found_double();
    return (res);

}

void Convert::print_cast()
{
    if (set_last() == -1)
        return ;
    if (_char != '0')
        std::cout << "char: '" << _char << "'" << std::endl;
    if (_int < std::numeric_limits<int>::min() && _int > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _int << std::endl;
    std::cout.precision(2);
    if (_float < std::numeric_limits<float>::min() && _float > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: "<< _float << "f" << std::endl;
    if (_double < std::numeric_limits<double>::min() && _double > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << _double << std::endl;
    return ;
}

void Convert::setSpe()
    {
        _spe = 1;
        return;
    }

int Convert::whichType(void)
{
    int i = -1;
    int length = _conv.length();
    int point = 0;
    char first_char = _conv.at(0);
    char last_char = _conv.at(length -1);
    if (_conv.length() == 1 && isprint(first_char) && !isdigit(first_char))
        return (_car);
    if (_conv == "-inff" || _conv == "+inff" || _conv == "nanf")
        return (setSpe(), _flo);
    if (_conv == "-inf" || _conv == "+inf" || _conv == "nan")
        return (setSpe(), _db);
    if (_conv[0] == '-')
        ++i;

    while (++i < length - 1)
    {
        if (((_conv[i] >= 33 && _conv[i] <= 45) || (_conv[i] == 47) || ((_conv[i] >= 58 && _conv[i] <= 126))) || point > 1)
            return (_error);
        if (_conv[i] == '.')
            point += 1;
    }
    if (last_char == 'f')
        return (_flo);
    else if (isalpha(last_char))
        return (_error);
    else if (point == 1)
        return (_db);
    
    else 
        return (_integ);
    return (0);
}