#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat b("b1",51);
    Form f("form",42,123);

	try
	{
		f.beSigned(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}