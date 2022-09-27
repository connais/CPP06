#include <iostream>
#include <stdint.h>
#include <cassert>
#include <cstdlib>
#include "Base.hpp"

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base * generate(void)
{
    int rando = (rand() % 3) + 1;
    if (rando == 1)
    {
        A *a = new A();
        return (a);
    }
    if (rando == 2)
    {
        B *b = new B();
        return (b);
    } 
    else
    {
        C *c = new C();
        return (c);
    }
}
void identify(Base* p)
{
    A *a = dynamic_cast<A *> (p);
    B *b = dynamic_cast<B *> (p);
    C *c = dynamic_cast<C *> (p);
    if (a != NULL)
        std::cout << "A" << std::endl;
    if (b != NULL)
        std::cout << "B" << std::endl;
    if (c != NULL)
        std::cout << "C" << std::endl;
}
void identify(Base& p)
{
    try
    {
        A & a = dynamic_cast<A&> (p);
        (void) a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception& e) 
    {
    //   std::cout << e.what() << std::endl;
    }

    try
    {
        B & b = dynamic_cast<B&> (p);
        (void) b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception& e) 
    {
    //    std::cout << e.what() << std::endl;
    }
    
    try
    {
        C & c = dynamic_cast<C&> (p);
        (void) c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception& e) 
    {
    //    std::cout << e.what() << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    int i = -1;
    while (++i < 10)
    {
        Base *ptr = generate();
        Base &adr = *ptr;

        identify(ptr);
        identify(adr);
        delete ptr;
    }
    
    return (0);
}
