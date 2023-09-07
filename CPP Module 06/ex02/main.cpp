#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate(void)
{
	int random;
	Base *randClass;

	random = rand() % 3;
	if (random == 0)
		randClass = new A;
	if (random == 1)
		randClass = new B;
	if (random == 2)
		randClass = new C;
	return randClass;
};

void identify(Base& p){
    try
	{
        A& x = dynamic_cast<A &>(p);
		(void)x;
        std::cout << "A is the identified type by referance" << std::endl;
    }
    catch (std::exception &e)
	{
    }
    try
	{
        B& x = dynamic_cast<B &>(p);
		(void)x;
        std::cout << "B is the identified type by referance" << std::endl;
    }
    catch (std::exception &e)
	{
    }
    try
	{
        C& x = dynamic_cast<C &>(p);
		(void)x;
        std::cout << "C is the identified type by referance" << std::endl;
    }
    catch (std::exception &e)
	{
    }

}
void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A is the identified type by pointer" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B is the identified type by pointer" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C is the identified type by pointer" << std::endl;
}

int main()
{
	Base *s = generate();

	identify(*s);
	identify(s);
}