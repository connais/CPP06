#include <iostream>
#include <stdint.h>
#include <cassert>

struct Data
{

public:

    uintptr_t   _cast;
};

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

int main()
{
    Data    test;
    test._cast = 1010;
    uintptr_t   found = serialize(&test);
    std::cout << "found : "<< found << std::endl;
    Data *ptr = deserialize(found);
    std::cout << "---return to initial value---" << std::endl;
    std::cout << "ptr : "<< ptr->_cast << std::endl;
    return (0);
}
