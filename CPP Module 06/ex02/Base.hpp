#ifndef BASE_HPP
#define BASE_HPP


class A;
class B;
class C;

#include <iostream>
#include <cstdlib>
#include <unistd.h>


class Base{
    public:
    virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif