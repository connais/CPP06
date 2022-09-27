#include "Convert.hpp"
int main(int argc, char *argv[])
{
    if (argc != 2)
        return (std::cout << "bad arguments" << std::endl, 0);
    Convert cast(argv[1]);

    cast.set_last();
}