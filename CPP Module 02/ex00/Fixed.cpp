#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpyFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_number = cpyFixed.fixed_point_number;
}

Fixed &Fixed::operator=(const Fixed &cpy)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->fixed_point_number = cpy.fixed_point_number;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}